/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#include "src/allocation.h"
#include "platform/assert.h"
#include "src/longjump.h"
#include "src/unit_test.h"

namespace Code {

class TestValueObject : public ValueObject {
 public:
  explicit TestValueObject(int* ptr) : ptr_(ptr) {
    EXPECT_EQ(1, *ptr_);
    *ptr_ = 2;
  }

  virtual ~TestValueObject() {
    EXPECT_EQ(3, *ptr_);
    *ptr_ = 4;
  }

  int value() const { return *ptr_; }
  virtual int GetId() const { return 3; }

 private:
  int* ptr_;
};

class TestStackResource : public StackResource {
 public:
  explicit TestStackResource(int* ptr)
      : StackResource(Thread::Current()), ptr_(ptr) {
    EXPECT_EQ(1, *ptr_);
    *ptr_ = 2;
  }

  ~TestStackResource() {
    EXPECT_EQ(6, *ptr_);
    *ptr_ = 7;
  }

  int value() const { return *ptr_; }
  virtual int GetId() const { return 3; }

 private:
  int* ptr_;
};

class TestStackedStackResource : public StackResource {
 public:
  explicit TestStackedStackResource(int* ptr)
      : StackResource(Thread::Current()), ptr_(ptr) {
    EXPECT_EQ(3, *ptr_);
    *ptr_ = 4;
  }

  ~TestStackedStackResource() {
    EXPECT_EQ(5, *ptr_);
    *ptr_ = 6;
  }

  int value() const { return *ptr_; }

 private:
  int* ptr_;
};

static void StackAllocatedDestructionHelper(int* ptr) {
  TestValueObject stacked(ptr);
  EXPECT_EQ(2, *ptr);
  *ptr = 3;
}

ISOLATE_UNIT_TEST_CASE(StackAllocatedDestruction) {
  int data = 1;
  StackAllocatedDestructionHelper(&data);
  EXPECT_EQ(4, data);
}

static void StackAllocatedLongJumpHelper(int* ptr, LongJumpScope* jump) {
  TestValueObject stacked(ptr);
  EXPECT_EQ(2, *ptr);
  *ptr = 3;
  const Error& error = Error::Handle(LanguageError::New(
      String::Handle(String::New("StackAllocatedLongJump"))));
  jump->Jump(1, error);
  UNREACHABLE();
}

ISOLATE_UNIT_TEST_CASE(StackAllocatedLongJump) {
  LongJumpScope jump;
  int data = 1;
  if (setjmp(*jump.Set()) == 0) {
    StackAllocatedLongJumpHelper(&data, &jump);
    UNREACHABLE();
  } else {
    ASSERT(Error::Handle(thread->StealStickyError()).IsLanguageError());
  }
  EXPECT_EQ(3, data);
}

static void StackedStackResourceDestructionHelper(int* ptr) {
  TestStackedStackResource stacked(ptr);
  EXPECT_EQ(4, *ptr);
  *ptr = 5;
}

static void StackResourceDestructionHelper(int* ptr) {
  TestStackResource stacked(ptr);
  EXPECT_EQ(2, *ptr);
  *ptr = 3;
  StackedStackResourceDestructionHelper(ptr);
  EXPECT_EQ(6, *ptr);
  // Do not set data because the LongJump version does not return control here.
}

ISOLATE_UNIT_TEST_CASE(StackResourceDestruction) {
  int data = 1;
  StackResourceDestructionHelper(&data);
  EXPECT_EQ(7, data);
}

static void StackedStackResourceLongJumpHelper(int* ptr, LongJumpScope* jump) {
  TestStackedStackResource stacked(ptr);
  EXPECT_EQ(4, *ptr);
  *ptr = 5;
  const Error& error = Error::Handle(LanguageError::New(
      String::Handle(String::New("StackedStackResourceLongJump"))));
  jump->Jump(1, error);
  UNREACHABLE();
}

static void StackResourceLongJumpHelper(int* ptr, LongJumpScope* jump) {
  TestStackResource stacked(ptr);
  EXPECT_EQ(2, *ptr);
  *ptr = 3;
  StackedStackResourceLongJumpHelper(ptr, jump);
  UNREACHABLE();
}

ISOLATE_UNIT_TEST_CASE(StackResourceLongJump) {
  LongJumpScope* base = Thread::Current()->long_jump_base();
  {
    LongJumpScope jump;
    int data = 1;
    if (setjmp(*jump.Set()) == 0) {
      StackResourceLongJumpHelper(&data, &jump);
      UNREACHABLE();
    } else {
      ASSERT(Error::Handle(thread->StealStickyError()).IsLanguageError());
    }
    EXPECT_EQ(7, data);
  }
  ASSERT(base == Thread::Current()->long_jump_base());
}

}  // namespace dart
