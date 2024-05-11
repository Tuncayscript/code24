#include "compiler.h"

namespace CodeAOTCompiler {

AOTCompiler::AOTCompiler(const std::string& source_code)
    : source_code_(source_code), module_(new llvm::Module("aot_module", llvm::getGlobalContext())),
      builder_(llvm::getGlobalContext()) {}

AOTCompiler::~AOTCompiler() = default;

std::unique_ptr<llvm::Module> AOTCompiler::Compile() {
  // Try parsing with Clang first (recommended)
  if (parseSourceWithClang()) {
    // Success! Perform optimizations and verification
    performOptimizationsAndVerification();
    return module_.release();
  }

  // If Clang parsing fails (optional):
  // Consider using your custom Tuncayscript parser here
  // - Implement IR generation logic based on the custom AST/IR
  //   (Replace the comment below with your custom parsing and IR generation)
  // // TODO: Implement custom Tuncayscript parsing and IR generation

  return nullptr; // Indicate compilation failure
}

bool AOTCompiler::parseSourceWithClang() {
  MyASTConsumer consumer;
  clang::CompilerInstance instance;
  instance.setASTConsumer(&consumer);
  instance.getDiagnostics().setDiagnosticOptions(clang::DiagnosticOptions());
  instance.getTargetOpts().Triple = llvm::sys::getDefaultTargetTriple();

  llvm::MemoryBuffer *buffer = llvm::MemoryBuffer::getMemBuffer(source_code_);
  // Adjust language options based on Tuncayscript syntax (if necessary)
  instance.getLangOpts().CPlusPlus = true; // Assuming some C++ compatibility
  // You might need to modify these options based on Tuncayscript's syntax
  instance.getLangOpts().// ... (Add specific language options for Tuncayscript)

  if (!instance.createDiagnostics(nullptr, true)) {
    return false;
  }

  const clang::FileSystemOptions& fso = instance.getFileManager().getFileSystemOpts();
  clang::FileManager virtual_fs(fso);
  const clang::VirtualFileSystem *vfs = virtual_fs.createVirtualFileSystem();
  instance.setVirtualFileSystem(vfs);
  instance.getDiagnostics().getClient()->setTarget(vfs);

  clang::UniqueVirtualFileOverlay content(buffer, instance.getVirtualFileSystem());
  clang::FileEntry *file = virtual_fs.addFile("source.tuncayscript", clang::FileEntryKind::RegularFile, content);
  instance.getSourceManager().setMainFileID(instance.getSourceManager().createFileID(file));
  instance.getASTContext().setLangOpts(instance.getLangOpts());

  if (!clang::ParseAST(instance, instance.getSourceManager().getMainFileID(), nullptr)) {
    error_ = consumer.getError();
    return false;
  }

  instance.getDiagnostics().getClient()->flushDiagnostics();
  vfs->releaseOverlay(content);
  instance.getVirtualFileSystem()->~VirtualFileSystem();
  delete buffer;

  // Implement IR generation logic based on the Clang AST (replace with your logic)
  //   - ... (Traverse the Clang AST and generate corresponding LLVM IR) ...

  return true;
}

void AOTCompiler::performOptimizationsAndVerification() {
  llvm::legacy::FunctionPassManager pm(llvm::getGlobalContext());
  pm.addPass(llvm::createFunctionInliningPass());
  pm.addPass(llvm::createInstructionCombiningPass());
  pm.run(*module_);

  if (llvm::verifyModule(*module_, &llvm::errs())) {
    // Handle verification errors (e.g., throw exception or log error)
    return; // Indicate compilation failure
  }
}

} // namespace CodeAOTCompiler
