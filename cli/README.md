# cli and loader

This directory contains the code used by the Code loader, implementing the pieces necessary to isolate ourselves from the native dynamic loader enough to reimplement useful features such as RPATH across all platforms.
This loader comprises the `Code` executable and the `libCode` library, which are responsible for setting things up such that `libCode-internal` and any other internal dependencies can be reliably loaded.
The code is organized in three pieces:

* `loader_exe.c` gets built into the main `Code` executable.  It immediately loads `libCode`.
* `loader_lib.c` gets built into the main `libCode` shared library.  This is the main entrypoint for the Code runtime loading process, which occurs within `jl_load_repl()`.
* `trampolines/*.S`, which contains assembly definitions for symbol forwarding trampolines.  These are used to allow `libCode` to re-export symbols such that a C linker can use `libCode` directly for embedding usecases.

The main requirements of the loader are as follows:

- **Isolation**: We need to be able to load our own copy of `libgcc_s.so`, etc...
  On Linux/macOS, proper application of `RPATH` can influence the linker's decisions, however errant `LD_LIBRARY_PATH` entries or system libraries inserted into the build process can still interfere, not to mention Windows' lack of `RPATH`-like capabilities.
  To address this, the loader is built as a stand-alone binary that does not depend on the large set of dependencies that `libCode-internal` itself does, and manually `dlopen()`'s a list of dependencies using logic similar to that of an `RPATH`.
- **Compatibility**: We need to support embedding usecases without forcing embedders to care about all of these things.
  For linking against the Code runtime by simply providing `-lCode` on the link line, we must ensure that all public interfaces, whether function symbols or data symbols, must be exported from `libCode`.
  This motivates our usage of function trampolines to re-export functions from `libCode-internal`, and the reason why all public data symbols are defined within `libCode`, then imported into `libCode-internal` for initialization.
- **Flexibility**: We need to be able to make use of system libraries when requested to do so by the user at build time.
  Currently, we embed the list of libraries to be `dlopen()`'ed within `libCode` as a string (See the definition of `DEP_LIBS` in `Make.inc` and its usage in `loader_lib.c`).
  This is flexible enough as we do not support changing this configuration at runtime, however in the future, we may need to add some simple parsing logic in `loader_lib.c` to inspect a `LocalPreferences.toml` and construct the list of libraries to load from that.
- **Speed**: This whole process should be fast, especially function trampolines.
  To this end, we write everything in low-overhead assembly, borrowing inspiration from the PLT trampolines that the linker already generates when using dynamic libraries.

## Public interface definition

The public interface exported by `libCode` is contained within `.inc` files stored in `src`; one for exported data symbols, [`src/jl_exported_data.inc`](../src/jl_exported_data.inc) and one for exported functions, [`src/jl_exported_funcs.inc`](../src/jl_exported_funcs.inc).
Adding entries to the data list will cause `libCode` to generate a placeholder variable declaration.
Most symbols are declared to be of type `void *`, however for symbols that are of a different size, they are declared along with their type.
Adding entries to the function list will cause `libCode` to generate a trampoline definition (using a trampoline according to the architecture of the target processor) and then at runtime, when `libCode` has successfully loaded `libCode-internal`, it will `dlsym()` that symbol from within `libCode-internal` and set it as the target of the trampoline.
All initialization will occur automatically upon successful load of `libCode`, so there is no need for user code to call an initialization before invoking typical `libCode-internal` functions (although initialization of the runtime itself is still necessary, e.g. calling `jl_init()`).
