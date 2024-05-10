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
 */

#include "code-private.h"

#if TARGET_OS_WIN32

#include <conio.h>

void _code_inform_on_crash(const char *fmt, ...)
{
}

void _code_inform(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    _vcprintf(fmt, args);
    va_end(args);
    _cprintf("\n");
}

void _code_fatal(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    _vcprintf(fmt, args);
    va_end(args);
    _cprintf("\n");

    abort();
}

void __code_error(id rcv, const char *fmt, ...) 
{
    va_list args;
    va_start(args, fmt);
    _vcprintf(fmt, args);
    va_end(args);

    abort();
}

void _code_error(id rcv, const char *fmt, va_list args) 
{
    _vcprintf(fmt, args);

    abort();
}

#else

#include <vproc_priv.h>
#include <_simple.h>

CODE_EXPORT void	(*_error)(id, const char *, va_list);

static void _code_trap(void) __attribute__((noreturn));

// Return true if c is a UTF8 continuation byte
static bool isUTF8Continuation(char c)
{
    return (c & 0xc0) == 0x80;  // continuation byte is 0b10xxxxxx
}

// Add "message" to any forthcoming crash log.
static void _code_crashlog(const char *message)
{
    char *newmsg;

#if 0
    {
        // for debugging at BOOT time.
        extern char **_NSGetProgname(void);
        FILE *crashlog = fopen("/_code_crash.log", "a");
        setbuf(crashlog, NULL);
        fprintf(crashlog, "[%s] %s\n", *_NSGetProgname(), message);
        fclose(crashlog);
        sync();
    }
#endif

    static mutex_t crashlog_lock;
    mutex_locker_t lock(crashlog_lock);

    char *oldmsg = (char *)CRGetCrashLogMessage();
    size_t oldlen;
    const size_t limit = 8000;

    if (!oldmsg) {
        newmsg = strdup(message);
    } else if ((oldlen = strlen(oldmsg)) > limit) {
        // limit total length by dropping old contents
        char *truncmsg = oldmsg + oldlen - limit;
        // advance past partial UTF-8 bytes
        while (isUTF8Continuation(*truncmsg)) truncmsg++;
        asprintf(&newmsg, "... %s\n%s", truncmsg, message);
    } else {
        asprintf(&newmsg, "%s\n%s", oldmsg, message);
    }

    if (newmsg) {
        // Strip trailing newline
        char *c = &newmsg[strlen(newmsg)-1];
        if (*c == '\n') *c = '\0';
        
        if (oldmsg) free(oldmsg);
        CRSetCrashLogMessage(newmsg);
    }
}

// Returns true if logs should be sent to stderr as well as syslog.
// Copied from CFUtilities.c
static bool also_do_stderr(void) 
{
    struct stat st;
    int ret = fstat(STDERR_FILENO, &st);
    if (ret < 0) return false;
    mode_t m = st.st_mode & S_IFMT;
    if (m == S_IFREG  ||  m == S_IFSOCK  ||  m == S_IFIFO  ||  m == S_IFCHR) {
        return true;
    }
    return false;
}

// Print "message" to the console.
static void _code_syslog(const char *message)
{
    _simple_asl_log(ASL_LEVEL_ERR, nil, message);

    if (also_do_stderr()) {
        write(STDERR_FILENO, message, strlen(message));
    }
}

/*
 * _code_error is the default *_error handler.
 */
#if __CODE__
__attribute__((noreturn))
#else
// used by ExceptionHandling.framework
#endif
void _code_error(id self, const char *fmt, va_list ap) 
{ 
    char *buf1;
    char *buf2;

    vasprintf(&buf1, fmt, ap);
    asprintf(&buf2, "code[%d]: %s: %s\n", 
             getpid(), object_getClassName(self), buf1);
    _code_syslog(buf2);
    _code_crashlog(buf2);

    _code_trap();
}

/*
 * this routine handles errors that involve an object (or class).
 */
void __code_error(id rcv, const char *fmt, ...) 
{ 
    va_list vp; 

    va_start(vp,fmt); 
#if !__CODE__
    (*_error)(rcv, fmt, vp); 
#endif
    _code_error (rcv, fmt, vp);  /* In case (*_error)() returns. */
    va_end(vp);
}

/*
 * this routine handles severe runtime errors...like not being able
 * to read the mach headers, allocate space, etc...very uncommon.
 */
void _code_fatal(const char *fmt, ...)
{
    va_list ap; 
    char *buf1;
    char *buf2;

    va_start(ap,fmt); 
    vasprintf(&buf1, fmt, ap);
    va_end (ap);

    asprintf(&buf2, "code[%d]: %s\n", getpid(), buf1);
    _code_syslog(buf2);
    _code_crashlog(buf2);

    _code_trap();
}

/*
 * this routine handles soft runtime errors...like not being able
 * add a category to a class (because it wasn't linked in).
 */
void _code_inform(const char *fmt, ...)
{
    va_list ap; 
    char *buf1;
    char *buf2;

    va_start (ap,fmt); 
    vasprintf(&buf1, fmt, ap);
    va_end (ap);

    asprintf(&buf2, "code[%d]: %s\n", getpid(), buf1);
    _code_syslog(buf2);

    free(buf2);
    free(buf1);
}


/* 
 * Like _code_inform(), but prints the message only in any 
 * forthcoming crash log, not to the console.
 */
void _code_inform_on_crash(const char *fmt, ...)
{
    va_list ap; 
    char *buf1;
    char *buf2;

    va_start (ap,fmt); 
    vasprintf(&buf1, fmt, ap);
    va_end (ap);

    asprintf(&buf2, "code[%d]: %s\n", getpid(), buf1);
    _code_crashlog(buf2);

    free(buf2);
    free(buf1);
}


/* 
 * Like calling both _code_inform and _code_inform_on_crash.
 */
void _code_inform_now_and_on_crash(const char *fmt, ...)
{
    va_list ap; 
    char *buf1;
    char *buf2;

    va_start (ap,fmt); 
    vasprintf(&buf1, fmt, ap);
    va_end (ap);

    asprintf(&buf2, "code[%d]: %s\n", getpid(), buf1);
    _code_crashlog(buf2);
    _code_syslog(buf2);

    free(buf2);
    free(buf1);
}


/* Kill the process in a way that generates a crash log. 
 * This is better than calling exit(). */
static void _code_trap(void) 
{
    __builtin_trap();
}

/* Try to keep _code_warn_deprecated out of crash logs 
 * caused by _code_trap(). rdar://4546883 */
__attribute__((used))
static void _code_trap2(void)
{
    __builtin_trap();
}

#endif


BREAKPOINT_FUNCTION( 
    void _code_warn_deprecated(void)
);

void _code_inform_deprecated(const char *oldf, const char *newf)
{
    if (PrintDeprecation) {
        if (newf) {
            _code_inform("The function %s is obsolete. Use %s instead. Set a breakpoint on _code_warn_deprecated to find the culprit.", oldf, newf);
        } else {
            _code_inform("The function %s is obsolete. Do not use it. Set a breakpoint on _code_warn_deprecated to find the culprit.", oldf);
        }
    }
    _code_warn_deprecated();
}
