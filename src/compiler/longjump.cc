#include "src/longjump.h"

#include "include/code_api.h"

#include "src/code_api_impl.h"
#include "src/isolate.h"
#include "src/object.h"
#include "src/os.h"

namespace Code {

jmp_buf* LongJumpScope::Set() {
  ASSERT(top_ == nullptr);
  top_ = Thread::Current()->top_resource();
  return &environment_;
}

void LongJumpScope::Jump(int value, const Error& error) {
  ASSERT(!error.IsNull());

  // Remember the error in the sticky error of this isolate.
  Thread::Current()->set_sticky_error(error);

  Jump(value);
}

void LongJumpScope::Jump(int value) {
  // A zero is the default return value from setting up a LongJumpScope
  // using Set.
  ASSERT(value != 0);

  Thread* thread = Thread::Current();
  DEBUG_ASSERT(thread->TopErrorHandlerIsSetJump());

  // Destruct all the active StackResource objects.
  StackResource::UnwindAbove(thread, top_);
  longjmp(environment_, value);
  UNREACHABLE();
}

}  // namespace dart
