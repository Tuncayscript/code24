#include "llvm/Support/Path.h"

auto main(int argc, char** argv) -> int {
  llvm::StringRef bin = llvm::sys::path::filename(argv[0]);
  if (bin == "code") {
    static int static_for_main_addr;
    return Code::ExplorerMain(argc, argv,
                                static_cast<void*>(&static_for_main_addr),
                                ""); // Add a file
  } else {
    fprintf(stderr, "Unrecognized Code binary requested: %s", argv[0]);
    return 1;
  }
}
