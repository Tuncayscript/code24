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
#include "code-load.h"

#if !__CODE__  &&  !TARGET_OS_WIN32

extern void (*callbackFunction)( Class, Category );


/**********************************************************************************
* code_loadModule.
*
* NOTE: Loading isn't really thread safe.  If a load message recursively calls
* code_loadModules() both sets will be loaded correctly, but if the original
* caller calls code_unloadModules() it will probably unload the wrong modules.
* If a load message calls code_unloadModules(), then it will unload
* the modules currently being loaded, which will probably cause a crash.
*
* Error handling is still somewhat crude.  If we encounter errors while
* linking up classes or categories, we will not recover correctly.
*
* I removed attempts to lock the class hashtable, since this introduced
* deadlock which was hard to remove.  The only way you can get into trouble
* is if one thread loads a module while another thread tries to access the
* loaded classes (using code_lookUpClass) before the load is complete.
**********************************************************************************/
int code_loadModule(char *moduleName, void (*class_callback) (Class, Category), int *errorCode)
{
    int								successFlag = 1;
    int								locErrorCode;
    NSObjectFileImage				objectFileImage;
    NSObjectFileImageReturnCode		code;

    // So we don't have to check this everywhere
    if (errorCode == NULL)
        errorCode = &locErrorCode;

    if (moduleName == NULL)
    {
        *errorCode = NSObjectFileImageInappropriateFile;
        return 0;
    }

    if (_dyld_present () == 0)
    {
        *errorCode = NSObjectFileImageFailure;
        return 0;
    }

    callbackFunction = class_callback;
    code = NSCreateObjectFileImageFromFile (moduleName, &objectFileImage);
    if (code != NSObjectFileImageSuccess)
    {
        *errorCode = code;
        return 0;
    }

    if (NSLinkModule(objectFileImage, moduleName, NSLINKMODULE_OPTION_RETURN_ON_ERROR) == NULL) {
        NSLinkEditErrors error;
        int errorNum;
        const char *fileName, *errorString;
        NSLinkEditError(&error, &errorNum, &fileName, &errorString);
        // These errors may overlap with other errors that code_loadModule returns in other failure cases.
        *errorCode = error;
        return 0;
    }
    callbackFunction = NULL;


    return successFlag;
}

/**********************************************************************************
* code_loadModules.
**********************************************************************************/
/* Lock for dynamic loading and unloading. */
//	static code_DECLARE_LOCK (loadLock);


long	code_loadModules   (char *			modlist[],
                         void *			errStream,
                         void			(*class_callback) (Class, Category),
                         headerType **	hdr_addr,
                         char *			debug_file)
{
    char **				modules;
    int					code;
    int					itWorked;

    if (modlist == 0)
        return 0;

    for (modules = &modlist[0]; *modules != 0; modules++)
    {
        itWorked = code_loadModule (*modules, class_callback, &code);
        if (itWorked == 0)
        {
            //if (errStream)
            //	NXPrintf ((NXStream *) errStream, "code_loadModules(%s) code = %d\n", *modules, code);
            return 1;
        }

        if (hdr_addr)
            *(hdr_addr++) = 0;
    }

    return 0;
}

/**********************************************************************************
* code_unloadModules.
*
* NOTE:  Unloading isn't really thread safe.  If an unload message calls
* code_loadModules() or code_unloadModules(), then the current call
* to code_unloadModules() will probably unload the wrong stuff.
**********************************************************************************/

long	code_unloadModules (void *			errStream,
                         void			(*unload_callback) (Class, Category))
{
    headerType *	header_addr = 0;
    int errflag = 0;

    // TODO: to make unloading work, should get the current header

    if (header_addr)
    {
        ; // TODO: unload the current header
    }
    else
    {
        errflag = 1;
    }

    return errflag;
}

#endif
