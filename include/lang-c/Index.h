/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 22, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef BUILDSYSTEM_H
#define BUILDSYSTEM_H

#include "lang-c/Platform.h"
#include "lang-c/CXErrorCode.h"
#include "lang-c/CXString.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup BUILD_SYSTEM Build system utilities
 * @{
 */

/**
 * Return the timestamp for use with Clang's
 * \c -fbuild-session-timestamp= option.
 */
CINDEX_LINKAGE unsigned long long clang_getBuildSessionTimestamp(void);

/**
 * Object encapsulating information about overlaying virtual
 * file/directories over the real file system.
 */
typedef struct CXVirtualFileOverlayImpl *CXVirtualFileOverlay;

/**
 * Create a \c CXVirtualFileOverlay object.
 * Must be disposed with \c clang_VirtualFileOverlay_dispose().
 *
 * \param options is reserved, always pass 0.
 */
CINDEX_LINKAGE CXVirtualFileOverlay
clang_VirtualFileOverlay_create(unsigned options);

/**
 * Map an absolute virtual file path to an absolute real one.
 * The virtual path must be canonicalized (not contain "."/"..").
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_VirtualFileOverlay_addFileMapping(CXVirtualFileOverlay,
                                        const char *virtualPath,
                                        const char *realPath);

/**
 * Set the case sensitivity for the \c CXVirtualFileOverlay object.
 * The \c CXVirtualFileOverlay object is case-sensitive by default, this
 * option can be used to override the default.
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_VirtualFileOverlay_setCaseSensitivity(CXVirtualFileOverlay,
                                            int caseSensitive);

/**
 * Write out the \c CXVirtualFileOverlay object to a char buffer.
 *
 * \param options is reserved, always pass 0.
 * \param out_buffer_ptr pointer to receive the buffer pointer, which should be
 * disposed using \c clang_free().
 * \param out_buffer_size pointer to receive the buffer size.
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_VirtualFileOverlay_writeToBuffer(CXVirtualFileOverlay, unsigned options,
                                       char **out_buffer_ptr,
                                       unsigned *out_buffer_size);

/**
 * free memory allocated by libclang, such as the buffer returned by
 * \c CXVirtualFileOverlay() or \c clang_ModuleMapDescriptor_writeToBuffer().
 *
 * \param buffer memory pointer to free.
 */
CINDEX_LINKAGE void clang_free(void *buffer);

/**
 * Dispose a \c CXVirtualFileOverlay object.
 */
CINDEX_LINKAGE void clang_VirtualFileOverlay_dispose(CXVirtualFileOverlay);

/**
 * Object encapsulating information about a module.map file.
 */
typedef struct CXModuleMapDescriptorImpl *CXModuleMapDescriptor;

/**
 * Create a \c CXModuleMapDescriptor object.
 * Must be disposed with \c clang_ModuleMapDescriptor_dispose().
 *
 * \param options is reserved, always pass 0.
 */
CINDEX_LINKAGE CXModuleMapDescriptor
clang_ModuleMapDescriptor_create(unsigned options);

/**
 * Sets the framework module name that the module.map describes.
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_ModuleMapDescriptor_setFrameworkModuleName(CXModuleMapDescriptor,
                                                 const char *name);

/**
 * Sets the umbrealla header name that the module.map describes.
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_ModuleMapDescriptor_setUmbrellaHeader(CXModuleMapDescriptor,
                                            const char *name);

/**
 * Write out the \c CXModuleMapDescriptor object to a char buffer.
 *
 * \param options is reserved, always pass 0.
 * \param out_buffer_ptr pointer to receive the buffer pointer, which should be
 * disposed using \c clang_free().
 * \param out_buffer_size pointer to receive the buffer size.
 * \returns 0 for success, non-zero to indicate an error.
 */
CINDEX_LINKAGE enum CXErrorCode
clang_ModuleMapDescriptor_writeToBuffer(CXModuleMapDescriptor, unsigned options,
                                       char **out_buffer_ptr,
                                       unsigned *out_buffer_size);

/**
 * Dispose a \c CXModuleMapDescriptor object.
 */
CINDEX_LINKAGE void clang_ModuleMapDescriptor_dispose(CXModuleMapDescriptor);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* BUILD_SYSTEM_H */
