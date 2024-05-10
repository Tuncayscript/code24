/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 *//***********************************************************************
* code-runtime.m
* Copyright 1988-1996, NeXT Software, Inc.
* Author:	s. naroff
*
**********************************************************************/



/***********************************************************************
* Imports.
**********************************************************************/

#include "code-private.h"
#include "code-loadmethod.h"
#include "message.h"

CODE_EXPORT Class getOriginalClassForPosingClass(Class);


/***********************************************************************
* Exports.
**********************************************************************/

// Settings from environment variables
#define OPTION(var, env, help) bool var = false;
#include "code-env.h"
#undef OPTION

struct option_t {
    bool* var;
    const char *env;
    const char *help;
    size_t envlen;
};

const option_t Settings[] = {
#define OPTION(var, env, help) option_t{&var, #env, help, strlen(#env)}, 
#include "code-env.h"
#undef OPTION
};


// code's key for pthread_getspecific
static tls_key_t _code_pthread_key;

// Selectors
SEL SEL_load = NULL;
SEL SEL_initialize = NULL;
SEL SEL_resolveInstanceMethod = NULL;
SEL SEL_resolveClassMethod = NULL;
SEL SEL_cxx_construct = NULL;
SEL SEL_cxx_destruct = NULL;
SEL SEL_retain = NULL;
SEL SEL_release = NULL;
SEL SEL_autorelease = NULL;
SEL SEL_retainCount = NULL;
SEL SEL_alloc = NULL;
SEL SEL_allocWithZone = NULL;
SEL SEL_dealloc = NULL;
SEL SEL_copy = NULL;
SEL SEL_new = NULL;
SEL SEL_finalize = NULL;
SEL SEL_forwardInvocation = NULL;
SEL SEL_tryRetain = NULL;
SEL SEL_isDeallocating = NULL;
SEL SEL_retainWeakReference = NULL;
SEL SEL_allowsWeakReference = NULL;


header_info *FirstHeader = 0;  // NULL means empty list
header_info *LastHeader  = 0;  // NULL means invalid; recompute it
int HeaderCount = 0;


/***********************************************************************
* code_getClass.  Return the id of the named class.  If the class does
* not exist, call _code_classLoader and then code_classHandler, either of 
* which may create a new class.
* Warning: doesn't work if aClassName is the name of a posed-for class's isa!
**********************************************************************/
Class code_getClass(const char *aClassName)
{
    if (!aClassName) return Nil;

    // NO unconnected, YES class handler
    return look_up_class(aClassName, NO, YES);
}


/***********************************************************************
* code_getRequiredClass.  
* Same as code_getClass, but kills the process if the class is not found. 
* This is used by ZeroLink, where failing to find a class would be a 
* compile-time link error without ZeroLink.
**********************************************************************/
Class code_getRequiredClass(const char *aClassName)
{
    Class cls = code_getClass(aClassName);
    if (!cls) _code_fatal("link error: class '%s' not found.", aClassName);
    return cls;
}


/***********************************************************************
* code_lookUpClass.  Return the id of the named class.
* If the class does not exist, call _code_classLoader, which may create 
* a new class.
*
* Formerly code_getClassWithoutWarning ()
**********************************************************************/
Class code_lookUpClass(const char *aClassName)
{
    if (!aClassName) return Nil;

    // NO unconnected, NO class handler
    return look_up_class(aClassName, NO, NO);
}


/***********************************************************************
* code_getMetaClass.  Return the id of the meta class the named class.
* Warning: doesn't work if aClassName is the name of a posed-for class's isa!
**********************************************************************/
Class code_getMetaClass(const char *aClassName)
{
    Class cls;

    if (!aClassName) return Nil;

    cls = code_getClass (aClassName);
    if (!cls)
    {
        _code_inform ("class `%s' not linked into application", aClassName);
        return Nil;
    }

    return cls->ISA();
}


/***********************************************************************
* appendHeader.  Add a newly-constructed header_info to the list. 
**********************************************************************/
void appendHeader(header_info *hi)
{
    // Add the header to the header list. 
    // The header is appended to the list, to preserve the bottom-up order.
    HeaderCount++;
    hi->next = NULL;
    if (!FirstHeader) {
        // list is empty
        FirstHeader = LastHeader = hi;
    } else {
        if (!LastHeader) {
            // list is not empty, but LastHeader is invalid - recompute it
            LastHeader = FirstHeader;
            while (LastHeader->next) LastHeader = LastHeader->next;
        }
        // LastHeader is now valid
        LastHeader->next = hi;
        LastHeader = hi;
    }
}


/***********************************************************************
* removeHeader
* Remove the given header from the header list.
* FirstHeader is updated. 
* LastHeader is set to NULL. Any code that uses LastHeader must 
* detect this NULL and recompute LastHeader by traversing the list.
**********************************************************************/
void removeHeader(header_info *hi)
{
    header_info **hiP;

    for (hiP = &FirstHeader; *hiP != NULL; hiP = &(**hiP).next) {
        if (*hiP == hi) {
            header_info *deadHead = *hiP;

            // Remove from the linked list (updating FirstHeader if necessary).
            *hiP = (**hiP).next;
            
            // Update LastHeader if necessary.
            if (LastHeader == deadHead) {
                LastHeader = NULL;  // will be recomputed next time it's used
            }

            HeaderCount--;
            break;
        }
    }
}


/***********************************************************************
* environ_init
* Read environment variables that affect the runtime.
* Also print environment variable help, if requested.
**********************************************************************/
void environ_init(void) 
{
    if (issetugid()) {
        // All environment variables are silently ignored when setuid or setgid
        // This includes code_HELP and code_PRINT_OPTIONS themselves.
        return;
    } 

    bool PrintHelp = false;
    bool PrintOptions = false;
    bool maybeMallocDebugging = false;

    // Scan environ[] directly instead of calling getenv() a lot.
    // This optimizes the case where none are set.
    for (char **p = *_NSGetEnviron(); *p != nil; p++) {
        if (0 == strncmp(*p, "Malloc", 6)  ||  0 == strncmp(*p, "DYLD", 4)  ||  
            0 == strncmp(*p, "NSZombiesEnabled", 16))
        {
            maybeMallocDebugging = true;
        }

        if (0 != strncmp(*p, "code_", 5)) continue;
        
        if (0 == strncmp(*p, "code_HELP=", 10)) {
            PrintHelp = true;
            continue;
        }
        if (0 == strncmp(*p, "code_PRINT_OPTIONS=", 19)) {
            PrintOptions = true;
            continue;
        }
        
        const char *value = strchr(*p, '=');
        if (!*value) continue;
        value++;
        
        for (size_t i = 0; i < sizeof(Settings)/sizeof(Settings[0]); i++) {
            const option_t *opt = &Settings[i];
            if ((size_t)(value - *p) == 1+opt->envlen  &&  
                0 == strncmp(*p, opt->env, opt->envlen))
            {
                *opt->var = (0 == strcmp(value, "YES"));
                break;
            }
        }            
    }

    // Special case: enable some autorelease pool debugging 
    // when some malloc debugging is enabled 
    // and code_DEBUG_POOL_ALLOCATION is not set to something other than NO.
    if (maybeMallocDebugging) {
        const char *insert = getenv("DYLD_INSERT_LIBRARIES");
        const char *zombie = getenv("NSZombiesEnabled");
        const char *pooldebug = getenv("code_DEBUG_POOL_ALLOCATION");
        if ((getenv("MallocStackLogging")
             || getenv("MallocStackLoggingNoCompact")
             || (zombie && (*zombie == 'Y' || *zombie == 'y'))
             || (insert && strstr(insert, "libgmalloc")))
            &&
            (!pooldebug || 0 == strcmp(pooldebug, "YES")))
        {
            DebugPoolAllocation = true;
        }
    }

    // Print code_HELP and code_PRINT_OPTIONS output.
    if (PrintHelp  ||  PrintOptions) {
        if (PrintHelp) {
            _code_inform("Objective-C runtime debugging. Set variable=YES to enable.");
            _code_inform("code_HELP: describe available environment variables");
            if (PrintOptions) {
                _code_inform("code_HELP is set");
            }
            _code_inform("code_PRINT_OPTIONS: list which options are set");
        }
        if (PrintOptions) {
            _code_inform("code_PRINT_OPTIONS is set");
        }

        for (size_t i = 0; i < sizeof(Settings)/sizeof(Settings[0]); i++) {
            const option_t *opt = &Settings[i];            
            if (PrintHelp) _code_inform("%s: %s", opt->env, opt->help);
            if (PrintOptions && *opt->var) _code_inform("%s is set", opt->env);
        }
    }
}


/***********************************************************************
* logReplacedMethod
* code_PRINT_REPLACED_METHODS implementation
**********************************************************************/
void 
logReplacedMethod(const char *className, SEL s, 
                  bool isMeta, const char *catName, 
                  IMP oldImp, IMP newImp)
{
    const char *oldImage = "??";
    const char *newImage = "??";

    // Silently ignore +load replacement because category +load is special
    if (s == SEL_load) return;

#if TARGET_OS_WIN32
    // don't know dladdr()/dli_fname equivalent
#else
    Dl_info dl;

    if (dladdr((void*)oldImp, &dl)  &&  dl.dli_fname) oldImage = dl.dli_fname;
    if (dladdr((void*)newImp, &dl)  &&  dl.dli_fname) newImage = dl.dli_fname;
#endif
    
    _code_inform("REPLACED: %c[%s %s]  %s%s  (IMP was %p (%s), now %p (%s))",
                 isMeta ? '+' : '-', className, sel_getName(s), 
                 catName ? "by category " : "", catName ? catName : "", 
                 oldImp, oldImage, newImp, newImage);
}



/***********************************************************************
* code_setMultithreaded.
**********************************************************************/
void code_setMultithreaded (BOOL flag)
{
    code_WARN_DEPRECATED;

    // Nothing here. Thread synchronization in the runtime is always active.
}


/***********************************************************************
* _code_fetch_pthread_data
* Fetch code's pthread data for this thread.
* If the data doesn't exist yet and create is NO, return NULL.
* If the data doesn't exist yet and create is YES, allocate and return it.
**********************************************************************/
_code_pthread_data *_code_fetch_pthread_data(bool create)
{
    _code_pthread_data *data;

    data = (_code_pthread_data *)tls_get(_code_pthread_key);
    if (!data  &&  create) {
        data = (_code_pthread_data *)
            calloc(1, sizeof(_code_pthread_data));
        tls_set(_code_pthread_key, data);
    }

    return data;
}


/***********************************************************************
* _code_pthread_destroyspecific
* Destructor for code's per-thread data.
* arg shouldn't be NULL, but we check anyway.
**********************************************************************/
extern void _destroyInitializingClassList(struct _code_initializing_classes *list);
void _code_pthread_destroyspecific(void *arg)
{
    _code_pthread_data *data = (_code_pthread_data *)arg;
    if (data != NULL) {
        _destroyInitializingClassList(data->initializingClasses);
        _destroySyncCache(data->syncCache);
        _destroyAltHandlerList(data->handlerList);
        for (int i = 0; i < (int)countof(data->printableNames); i++) {
            if (data->printableNames[i]) {
                free(data->printableNames[i]);  
            }
        }

        // add further cleanup here...

        free(data);
    }
}


void tls_init(void)
{
#if SUPPORT_DIRECT_THREAD_KEYS
    _code_pthread_key = TLS_DIRECT_KEY;
    pthread_key_init_np(TLS_DIRECT_KEY, &_code_pthread_destroyspecific);
#else
    _code_pthread_key = tls_create(&_code_pthread_destroyspecific);
#endif
}


/***********************************************************************
* _codeInit
* Former library initializer. This function is now merely a placeholder 
* for external callers. All runtime initialization has now been moved 
* to map_images() and _code_init.
**********************************************************************/
void _codeInit(void)
{
    // do nothing
}


/***********************************************************************
* code_setForwardHandler
**********************************************************************/

#if !__CODE__

// Default forward handler (nil) goes to forward:: dispatch.
void *_code_forward_handler = nil;
void *_code_forward_stret_handler = nil;

#else

// Default forward handler halts the process.
__attribute__((noreturn)) void 
code_defaultForwardHandler(id self, SEL sel)
{
    _code_fatal("%c[%s %s]: unrecognized selector sent to instance %p "
                "(no message forward handler is installed)", 
                class_isMetaClass(object_getClass(self)) ? '+' : '-', 
                object_getClassName(self), sel_getName(sel), self);
}
void *_code_forward_handler = (void*)code_defaultForwardHandler;

#if SUPPORT_STRET
struct stret { int i[100]; };
__attribute__((noreturn)) struct stret 
code_defaultForwardStretHandler(id self, SEL sel)
{
    code_defaultForwardHandler(self, sel);
}
void *_code_forward_stret_handler = (void*)code_defaultForwardStretHandler;
#endif

#endif

void code_setForwardHandler(void *fwd, void *fwd_stret)
{
    _code_forward_handler = fwd;
#if SUPPORT_STRET
    _code_forward_stret_handler = fwd_stret;
#endif
}


#if !__CODE__
// GrP fixme
extern "C" Class _code_getOrigClass(const char *name);
#endif
const char *class_getImageName(Class cls)
{
#if TARGET_OS_WIN32
    TCHAR *szFileName;
    DWORD charactersCopied;
    Class origCls;
    HMODULE classModule;
    bool res;
#endif
    if (!cls) return NULL;

#if !__CODE__
    cls = _code_getOrigClass(cls->demangledName());
#endif
#if TARGET_OS_WIN32
    charactersCopied = 0;
    szFileName = malloc(MAX_PATH * sizeof(TCHAR));
    
    origCls = code_getOrigClass(cls->demangledName());
    classModule = NULL;
    res = GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)origCls, &classModule);
    if (res && classModule) {
        charactersCopied = GetModuleFileName(classModule, szFileName, MAX_PATH * sizeof(TCHAR));
    }
    if (classModule) FreeLibrary(classModule);
    if (charactersCopied) {
        return (const char *)szFileName;
    } else {
        free(szFileName);
    }
    return NULL;
#else
    return dyld_image_path_containing_address(cls);
#endif
}


const char **code_copyImageNames(unsigned int *outCount)
{
    header_info *hi;
    int count = 0;
    int max = HeaderCount;
#if TARGET_OS_WIN32
    const TCHAR **names = (const TCHAR **)calloc(max+1, sizeof(TCHAR *));
#else
    const char **names = (const char **)calloc(max+1, sizeof(char *));
#endif
    
    for (hi = FirstHeader; hi != NULL && count < max; hi = hi->next) {
#if TARGET_OS_WIN32
        if (hi->moduleName) {
            names[count++] = hi->moduleName;
        }
#else
        if (hi->fname) {
            names[count++] = hi->fname;
        }
#endif
    }
    names[count] = NULL;
    
    if (count == 0) {
        // Return NULL instead of empty list if there are no images
        free((void *)names);
        names = NULL;
    }

    if (outCount) *outCount = count;
    return names;
}


/**********************************************************************
*
**********************************************************************/
const char ** 
code_copyClassNamesForImage(const char *image, unsigned int *outCount)
{
    header_info *hi;

    if (!image) {
        if (outCount) *outCount = 0;
        return NULL;
    }

    // Find the image.
    for (hi = FirstHeader; hi != NULL; hi = hi->next) {
#if TARGET_OS_WIN32
        if (0 == wcscmp((TCHAR *)image, hi->moduleName)) break;
#else
        if (0 == strcmp(image, hi->fname)) break;
#endif
    }
    
    if (!hi) {
        if (outCount) *outCount = 0;
        return NULL;
    }

    return _code_copyClassNamesForImage(hi, outCount);
}
	

/**********************************************************************
* Fast Enumeration Support
**********************************************************************/

static void (*enumerationMutationHandler)(id);

/**********************************************************************
* code_enumerationMutation
* called by compiler when a mutation is detected during foreach iteration
**********************************************************************/
void code_enumerationMutation(id object) {
    if (enumerationMutationHandler == nil) {
        _code_fatal("mutation detected during 'for(... in ...)'  enumeration of object %p.", (void*)object);
    }
    (*enumerationMutationHandler)(object);
}


/**********************************************************************
* code_setEnumerationMutationHandler
* an entry point to customize mutation error handing
**********************************************************************/
void code_setEnumerationMutationHandler(void (*handler)(id)) {
    enumerationMutationHandler = handler;
}


/**********************************************************************
* Associative Reference Support
**********************************************************************/

id code_getAssociatedObject_non_gc(id object, const void *key) {
    return _object_get_associative_reference(object, (void *)key);
}


void code_setAssociatedObject_non_gc(id object, const void *key, id value, code_AssociationPolicy policy) {
    _object_set_associative_reference(object, (void *)key, value, policy);
}


#if SUPPORT_GC

id code_getAssociatedObject_gc(id object, const void *key) {
    // auto_zone doesn't handle tagged pointer objects. Track it ourselves.
    if (object->isTaggedPointer()) return code_getAssociatedObject_non_gc(object, key);

    return (id)auto_zone_get_associative_ref(gc_zone, object, (void *)key);
}

void code_setAssociatedObject_gc(id object, const void *key, id value, code_AssociationPolicy policy) {
    // auto_zone doesn't handle tagged pointer objects. Track it ourselves.
    if (object->isTaggedPointer()) return code_setAssociatedObject_non_gc(object, key, value, policy);

    if ((policy & code_ASSOCIATION_COPY_NONATOMIC) == code_ASSOCIATION_COPY_NONATOMIC) {
        value = ((id(*)(id, SEL))code_msgSend)(value, SEL_copy);
    }
    auto_zone_set_associative_ref(gc_zone, object, (void *)key, value);
}

// code_setAssociatedObject and code_getAssociatedObject are 
// resolver functions in code-auto.mm.

#else

id 
code_getAssociatedObject(id object, const void *key) 
{
    return code_getAssociatedObject_non_gc(object, key);
}

void 
code_setAssociatedObject(id object, const void *key, id value, 
                         code_AssociationPolicy policy) 
{
    code_setAssociatedObject_non_gc(object, key, value, policy);
}

#endif


void code_removeAssociatedObjects(id object) 
{
#if SUPPORT_GC
    if (UseGC) {
        auto_zone_erase_associative_refs(gc_zone, object);
    } else 
#endif
    {
        if (object && object->hasAssociatedObjects()) {
            _object_remove_assocations(object);
        }
    }
}

