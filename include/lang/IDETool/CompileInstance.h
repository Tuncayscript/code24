//===--- CompileInstance.h ------------------------------------------------===//
//
// This source file is part of the Code Programming Language open source project
//
// Copyright (c) 2021 ITGSS Technologies and the Code project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See code/LICENSE.txt for license information
// See code/CONTRIBUTORS.txt for the list of Code project authors
//
//===----------------------------------------------------------------------===//

#ifndef CODE_IDE_COMPILEINSTANCE_H
#define CODE_IDE_COMPILEINSTANCE_H

#include "code/Frontend/Frontend.h"
#include "llvm/ADT/Hashing.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Chrono.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/VirtualFileSystem.h"

namespace code {

class CompilerInstance;
class DiagnosticConsumer;
class PluginRegistry;

namespace ide {

/// Manages \c CompilerInstance for completion like operations.
class CompileInstance {
  const std::string &SwiftExecutablePath;
  const std::string &RuntimeResourcePath;
  const std::string &DiagnosticDocumentationPath;
  const std::shared_ptr<swift::PluginRegistry> Plugins;

  struct Options {
    unsigned MaxASTReuseCount = 100;
    unsigned DependencyCheckIntervalSecond = 5;
  } Opts;

  std::mutex mtx;

  std::unique_ptr<CompilerInstance> CI;
  llvm::hash_code CachedArgHash;
  std::atomic<bool> CachedCIInvalidated;
  llvm::sys::TimePoint<> DependencyCheckedTimestamp;
  llvm::StringMap<llvm::hash_code> InMemoryDependencyHash;
  unsigned CachedReuseCount;

  bool shouldCheckDependencies() const;

  /// Perform cached sema. Returns \c true if the CI is not reusable.
  bool performCachedSemaIfPossible(DiagnosticConsumer *DiagC);

  /// Setup the CI with \p Args . Returns \c true if failed.
  bool setupCI(llvm::ArrayRef<const char *> Args,
                 llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FileSystem,
                 DiagnosticConsumer *DiagC);

  /// Perform Parse and Sema, potentially CI from previous compilation is
  /// reused. Returns \c true if there was any error.
  bool performSema(llvm::ArrayRef<const char *> Args,
                   llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FileSystem,
                   DiagnosticConsumer *DiagC,
                   std::shared_ptr<std::atomic<bool>> CancellationFlag);

public:
  CompileInstance(const std::string &SwiftExecutablePath,
                  const std::string &RuntimeResourcePath,
                  const std::string &DiagnosticDocumentationPath,
                  std::shared_ptr<swift::PluginRegistry> Plugins = nullptr)
      : SwiftExecutablePath(SwiftExecutablePath),
        RuntimeResourcePath(RuntimeResourcePath),
        DiagnosticDocumentationPath(DiagnosticDocumentationPath),
        Plugins(Plugins), CachedCIInvalidated(false), CachedReuseCount(0) {}

  /// NOTE: \p Args is only used for checking the equaity of the invocation.
  /// Since this function assumes that it is already normalized, exact the same
  /// arguments including their order is considered as the same invocation.
  bool
  performCompile(llvm::ArrayRef<const char *> Args,
                 llvm::IntrusiveRefCntPtr<llvm::vfs::FileSystem> FileSystem,
                 DiagnosticConsumer *DiagC,
                 std::shared_ptr<std::atomic<bool>> CancellationFlag);
};

} // namespace ide
} // namespace code

#endif // CODE_IDE_COMPILEINSTANCE_H
