#ifndef RUNTIME_VM_NATIVE_FUNCTION_H_
#define RUNTIME_VM_NATIVE_FUNCTION_H_

#include "src/allocation.h"

#include "include/code_api.h"

namespace Code {

// Forward declarations.
class NativeArguments;

// We have three variants of native functions:
//  - bootstrap natives, which are called directly from stub code. The callee is
//    responsible for safepoint transitions and setting up handle scopes as
//    needed. Only VM-defined natives are bootstrap natives; they cannot be
//    defined by embedders.
//  - no scope natives, which are called through a wrapper function. The wrapper
//    function handles the safepoint transition. The callee is responsible for
//    setting up API scopes as needed.
//  - auto scope natives, which are called through a wrapper function. The
//    wrapper function handles the safepoint transition and sets up an API
//    scope.

typedef void (*NativeFunction)(NativeArguments* arguments);
typedef void (*NativeFunctionWrapper)(CODE_NativeArguments args,
                                      CODE_NativeFunction func);

}  // namespace code

#endif  // RUNTIME_VM_NATIVE_FUNCTION_H_
