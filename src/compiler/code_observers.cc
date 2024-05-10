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

#include "src/code_observers.h"

#include "src/os.h"
#include "src/os_thread.h"

namespace Code {

#ifndef PRODUCT

Mutex* CodeObservers::mutex_ = nullptr;
intptr_t CodeObservers::observers_length_ = 0;
CodeObserver** CodeObservers::observers_ = nullptr;

class ExternalCodeObserverAdapter : public CodeObserver {
 public:
  explicit ExternalCodeObserverAdapter(CODE_CodeObserver delegate)
      : delegate_(delegate) {}

  virtual bool IsActive() const { return true; }

  virtual void Notify(const char* name,
                      uword base,
                      uword prologue_offset,
                      uword size,
                      bool optimized,
                      const CodeComments* comments) {
    return delegate_.on_new_code(&delegate_, name, base, size);
  }

 private:
  CODE_CodeObserver delegate_;
};

void CodeObservers::RegisterExternal(CODE_CodeObserver observer) {
  Register(new ExternalCodeObserverAdapter(observer));
}

void CodeObservers::Register(CodeObserver* observer) {
  observers_length_++;
  observers_ = reinterpret_cast<CodeObserver**>(
      realloc(observers_, sizeof(observer) * observers_length_));
  observers_[observers_length_ - 1] = observer;
}

void CodeObservers::NotifyAll(const char* name,
                              uword base,
                              uword prologue_offset,
                              uword size,
                              bool optimized,
                              const CodeComments* comments) {
  ASSERT(!AreActive() || (strlen(name) != 0));
  for (intptr_t i = 0; i < observers_length_; i++) {
    if (observers_[i]->IsActive()) {
      observers_[i]->Notify(name, base, prologue_offset, size, optimized,
                            comments);
    }
  }
}

bool CodeObservers::AreActive() {
  for (intptr_t i = 0; i < observers_length_; i++) {
    if (observers_[i]->IsActive()) return true;
  }
  return false;
}

void CodeObservers::Cleanup() {
  for (intptr_t i = 0; i < observers_length_; i++) {
    delete observers_[i];
  }
  free(observers_);
  observers_length_ = 0;
  observers_ = nullptr;
}

void CodeObservers::Init() {
  if (mutex_ == nullptr) {
    mutex_ = new Mutex();
  }
  ASSERT(mutex_ != nullptr);
  OS::RegisterCodeObservers();
}

#endif  // !PRODUCT

}  // namespace dart
