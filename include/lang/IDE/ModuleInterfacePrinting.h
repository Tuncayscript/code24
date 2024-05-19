//===--- ModuleInterfacePrinting.h - Routines to print module interface ---===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2023 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_MODULE_INTERFACE_PRINTING_H
#define CODE_IDE_MODULE_INTERFACE_PRINTING_H

#include "code/Basic/LLVM.h"
#include "code/Basic/OptionSet.h"

#include <string>
#include <vector>

namespace clang {
class Module;
}

namespace code {
class ASTContext;
class ASTPrinter;
class ModuleDecl;
class SourceFile;
class Type;
struct PrintOptions;

namespace ide {

/// Flags used when traversing a module for printing.
enum class ModuleTraversal : unsigned {
  /// Visit modules even if their contents wouldn't be visible to name lookup.
  VisitHidden     = 0x01,
  /// Visit submodules.
  VisitSubmodules = 0x02,
  /// Skip the declarations in a Code overlay module.
  SkipOverlay     = 0x04,
};

/// Options used to describe the traversal of a module for printing.
using ModuleTraversalOptions = OptionSet<ModuleTraversal>;

void collectModuleGroups(ModuleDecl *M, SmallVectorImpl<StringRef> &Into);

llvm::Optional<StringRef> findGroupNameForUSR(ModuleDecl *M, StringRef USR);

bool printTypeInterface(ModuleDecl *M, Type Ty, ASTPrinter &Printer,
                        std::string &TypeName, std::string &Error);

bool printTypeInterface(ModuleDecl *M, StringRef TypeUSR, ASTPrinter &Printer,
                        std::string &TypeName, std::string &Error);

void printModuleInterface(ModuleDecl *M, ArrayRef<StringRef> GroupNames,
                          ModuleTraversalOptions TraversalOptions,
                          ASTPrinter &Printer, const PrintOptions &Options,
                          const bool PrintSynthesizedExtensions);

/// Print the interface for a header that has been imported via the implicit
/// objc header importing feature.
void printHeaderInterface(StringRef Filename, ASTContext &Ctx,
                          ASTPrinter &Printer, const PrintOptions &Options);


/// Print the interface for a given swift source file.
void printSwiftSourceInterface(SourceFile &File, ASTPrinter &Printer,
                               const PrintOptions &Options);

/// Print the symbolic Code interface for a given imported clang module.
void printSymbolicSwiftClangModuleInterface(ModuleDecl *M, ASTPrinter &Printer,
                                            const clang::Module *clangModule);

} // namespace ide

} // namespace code

#endif // CODE_IDE_MODULE_INTERFACE_PRINTING_H
