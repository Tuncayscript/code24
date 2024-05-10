#include "src/longjump.h"
#include "src/thread.h"
#include "src/unit_test.h"

namespace Code {

static void LongJumpHelper(LongJumpScope* jump) {
  const Error& error = Error::Handle(
      LanguageError::New(String::Handle(String::New("LongJumpHelper"))));
  jump->Jump(1, error);
  UNREACHABLE();
}

ISOLATE_UNIT_TEST_CASE(LongJump) {
  LongJumpScope* base = Thread::Current()->long_jump_base();
  {
    LongJumpScope jump;
    if (setjmp(*jump.Set()) == 0) {
      LongJumpHelper(&jump);
      UNREACHABLE();
    } else {
      ASSERT(Error::Handle(thread->StealStickyError()).IsLanguageError());
    }
  }
  ASSERT(base == Thread::Current()->long_jump_base());
}

}  // namespace dart
