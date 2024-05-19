//===--- SyntacticMacroExpansion.h ----------------------------------------===//
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

#ifndef CODE_IDE_SYNTACTICMACROEXPANSION_H
#define CODE_IDE_SYNTACTICMACROEXPANSION_H

#include "code/AST/Decl.h"
#include "code/AST/MacroDefinition.h"
#include "code/AST/PluginRegistry.h"
#include "code/Basic/Fingerprint.h"
#include "code/Frontend/Frontend.h"
#include "llvm/Support/MemoryBuffer.h"

namespace code {

class ASTContext;
class SourceFile;

namespace ide {
class SourceEditConsumer;

/// Simple object to specify a syntactic macro expansion.
struct MacroExpansionSpecifier {
  unsigned offset;
  swift::MacroRoles macroRoles;
  swift::MacroDefinition macroDefinition;
};

/// Instance of a syntactic macro expansion context. This is created for each
/// list of compiler arguments (i.e. 'argHash'), and reused as long as the
/// compiler arguments are not changed.
class SyntacticMacroExpansionInstance {
  CompilerInvocation invocation;

  SourceManager SourceMgr;
  DiagnosticEngine Diags{SourceMgr};
  std::unique_ptr<ASTContext> Ctx;
  ModuleDecl *TheModule = nullptr;
  llvm::StringMap<MacroDecl *> MacroDecls;

  /// Create 'SourceFile' using the buffer.
  swift::SourceFile *getSourceFile(llvm::MemoryBuffer *inputBuf);

  /// Synthesize 'MacroDecl' AST object to use the expansion.
  swift::MacroDecl *
  getSynthesizedMacroDecl(swift::Identifier name,
                          const MacroExpansionSpecifier &expansion);

  /// Expand single 'expansion' in SF.
  void expand(swift::SourceFile *SF,
                    const MacroExpansionSpecifier &expansion,
                    SourceEditConsumer &consumer);

public:
  SyntacticMacroExpansionInstance() {}

  /// Setup the instance with \p args .
  bool setup(StringRef SwiftExecutablePath, ArrayRef<const char *> args,
             std::shared_ptr<PluginRegistry> plugins, std::string &error);

  ASTContext &getASTContext() { return *Ctx; }

  /// Expand all macros in \p inputBuf and send the edit results to \p consumer.
  /// Expansions are specified by \p expansions .
  void expandAll(llvm::MemoryBuffer *inputBuf,
                     ArrayRef<MacroExpansionSpecifier> expansions,
                     SourceEditConsumer &consumer);
};

/// Manager object to vend 'SyntacticMacroExpansionInstance'.
class SyntacticMacroExpansion {
  StringRef SwiftExecutablePath;
  std::shared_ptr<PluginRegistry> Plugins;

public:
  SyntacticMacroExpansion(StringRef SwiftExecutablePath,
                          std::shared_ptr<PluginRegistry> Plugins)
      : SwiftExecutablePath(SwiftExecutablePath), Plugins(Plugins) {}

  /// Get instance configured with the specified compiler arguments.
  std::shared_ptr<SyntacticMacroExpansionInstance>
  getInstance(ArrayRef<const char *> args, std::string &error);
};

} // namespace ide
} // namespace code

#endif // CODE_IDE_SYNTACTICMACROEXPANSION_H
