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

#ifndef CXCOMPILATIONDATABASE_H
#define CXCOMPILATIONDATABASE_H

#include "lang-c/Platform.h"
#include "lang-c/CXString.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup COMPILATIONDB CompilationDatabase functions
 * \ingroup CINDEX
 *
 * @{
 */

/**
 * A compilation database holds all information used to compile files in a
 * project. For each file in the database, it can be queried for the working
 * directory or the command line used for the compiler invocation.
 *
 * Must be freed by \c lang_CompilationDatabase_dispose
 */
typedef void * CXCompilationDatabase;

/**
 * Contains the results of a search in the compilation database
 *
 * When searching for the compile command for a file, the compilation db can
 * return several commands, as the file may have been compiled with
 * different options in different places of the project. This choice of compile
 * commands is wrapped in this opaque data structure. It must be freed by
 * \c lang_CompileCommands_dispose.
 */
typedef void * CXCompileCommands;

/**
 * Represents the command line invocation to compile a specific file.
 */
typedef void * CXCompileCommand;

/**
 * Error codes for Compilation Database
 */
typedef enum  {
  /*
   * No error occurred
   */
  CXCompilationDatabase_NoError = 0,

  /*
   * Database can not be loaded
   */
  CXCompilationDatabase_CanNotLoadDatabase = 1

} CXCompilationDatabase_Error;

/**
 * Creates a compilation database from the database found in directory
 * buildDir. For example, CMake can output a compile_commands.json which can
 * be used to build the database.
 *
 * It must be freed by \c lang_CompilationDatabase_dispose.
 */
CINDEX_LINKAGE CXCompilationDatabase
lang_CompilationDatabase_fromDirectory(const char *BuildDir,
                                        CXCompilationDatabase_Error *ErrorCode);

/**
 * Free the given compilation database
 */
CINDEX_LINKAGE void
lang_CompilationDatabase_dispose(CXCompilationDatabase);

/**
 * Find the compile commands used for a file. The compile commands
 * must be freed by \c lang_CompileCommands_dispose.
 */
CINDEX_LINKAGE CXCompileCommands
lang_CompilationDatabase_getCompileCommands(CXCompilationDatabase,
                                             const char *CompleteFileName);

/**
 * Get all the compile commands in the given compilation database.
 */
CINDEX_LINKAGE CXCompileCommands
lang_CompilationDatabase_getAllCompileCommands(CXCompilationDatabase);

/**
 * Free the given CompileCommands
 */
CINDEX_LINKAGE void lang_CompileCommands_dispose(CXCompileCommands);

/**
 * Get the number of CompileCommand we have for a file
 */
CINDEX_LINKAGE unsigned
lang_CompileCommands_getSize(CXCompileCommands);

/**
 * Get the I'th CompileCommand for a file
 *
 * Note : 0 <= i < lang_CompileCommands_getSize(CXCompileCommands)
 */
CINDEX_LINKAGE CXCompileCommand
lang_CompileCommands_getCommand(CXCompileCommands, unsigned I);

/**
 * Get the working directory where the CompileCommand was executed from
 */
CINDEX_LINKAGE CXString
lang_CompileCommand_getDirectory(CXCompileCommand);

/**
 * Get the filename associated with the CompileCommand.
 */
CINDEX_LINKAGE CXString
lang_CompileCommand_getFilename(CXCompileCommand);

/**
 * Get the number of arguments in the compiler invocation.
 *
 */
CINDEX_LINKAGE unsigned
lang_CompileCommand_getNumArgs(CXCompileCommand);

/**
 * Get the I'th argument value in the compiler invocations
 *
 * Invariant :
 *  - argument 0 is the compiler executable
 */
CINDEX_LINKAGE CXString
lang_CompileCommand_getArg(CXCompileCommand, unsigned I);

/**
 * Get the number of source mappings for the compiler invocation.
 */
CINDEX_LINKAGE unsigned
lang_CompileCommand_getNumMappedSources(CXCompileCommand);

/**
 * Get the I'th mapped source path for the compiler invocation.
 */
CINDEX_LINKAGE CXString
lang_CompileCommand_getMappedSourcePath(CXCompileCommand, unsigned I);

/**
 * Get the I'th mapped source content for the compiler invocation.
 */
CINDEX_LINKAGE CXString
lang_CompileCommand_getMappedSourceContent(CXCompileCommand, unsigned I);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif
