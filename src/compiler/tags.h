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

#ifndef RUNTIME_VM_TAGS_H_
#define RUNTIME_VM_TAGS_H_

#include "platform/growable_array.h"
#include "src/allocation.h"
#include "src/os_thread.h"
#include "src/thread_stack_resource.h"

namespace Code {

class Isolate;
class JSONObject;
class RuntimeEntry;

#define VM_TAG_LIST(V)                                                         \
  V(Idle)     /* isolate is idle and is_runnable() */                          \
  V(LoadWait) /* isolate is idle and !is_runnable() */                         \
  V(VM)       /* Catch all */                                                  \
  V(CompileOptimized)                                                          \
  V(CompileUnoptimized)                                                        \
  V(ClassLoading)                                                              \
  V(CompileParseRegExp)                                                        \
  V(Dart)                                                                      \
  V(GCNewSpace)                                                                \
  V(GCOldSpace)                                                                \
  V(GCIdle)                                                                    \
  V(Embedder)                                                                  \
  V(Runtime)                                                                   \
  V(Native)

class VMTag : public AllStatic {
 public:
  enum VMTagId {
    kInvalidTagId = 0,
#define DEFINE_VM_TAG_ID(tag) k##tag##TagId,
    VM_TAG_LIST(DEFINE_VM_TAG_ID)
#undef DEFINE_VM_TAG_KIND
        kNumVMTags,
    //
    // All tags below |kNumVMTags| are special meta-data tags and do not
    // indicate the state of the VM during a sample.
    //
    kRootTagId,       // Special tag used as root of all profiles.
    kTruncatedTagId,  // Special tag used to indicate a truncated call stack.
    // Code transition tags (used by unit tests).
    kNoneCodeTagId,
    kOptimizedCodeTagId,
    kUnoptimizedCodeTagId,
    kNativeCodeTagId,
    kInlineStartCodeTagId,
    kInlineEndCodeTagId,
    kLastTagId,
  };

  static bool IsVMTag(uword id) {
    return (id != kInvalidTagId) && (id < kNumVMTags);
  }
  static const char* TagName(uword id);
  static bool IsNativeEntryTag(uword id);
  static bool IsDartTag(uword id) { return id == kDartTagId; }
  static bool IsExitFrameTag(uword id);
  static bool IsRuntimeEntryTag(uword id);
  static const char* RuntimeEntryTagName(uword id);

  static void RegisterRuntimeEntry(RuntimeEntry* runtime_entry);

 private:
  struct TagEntry {
    const char* name;
    uword id;
  };
  static const TagEntry entries_[];
};

class VMTagScope : ThreadStackResource {
 public:
  VMTagScope(Thread* thread, uword tag, bool conditional_set = true);
  ~VMTagScope();

 private:
  uword previous_tag_;

  DISALLOW_ALLOCATION();
  DISALLOW_IMPLICIT_CONSTRUCTORS(VMTagScope);
};

class VMTagCounters {
 public:
  VMTagCounters();

  void Increment(uword tag);

  int64_t count(uword tag);

#ifndef PRODUCT
  void PrintToJSONObject(JSONObject* obj);
#endif  // !PRODUCT

 private:
  int64_t counters_[VMTag::kNumVMTags];
};

class UserTags : public AllStatic {
 public:
  // UserTag id space: [kUserTagIdOffset, kUserTagIdOffset + kMaxUserTags).
  static constexpr intptr_t kMaxUserTags = 256;
  static constexpr uword kUserTagIdOffset = 0x4096;
  static constexpr uword kDefaultUserTag = kUserTagIdOffset;
  static const char* TagName(uword tag_id);
  static bool IsUserTag(uword tag_id) {
    return (tag_id >= kUserTagIdOffset) &&
           (tag_id < kUserTagIdOffset + kMaxUserTags);
  }
  static void AddStreamableTagName(const char* tag);
  static void RemoveStreamableTagName(const char* tag);
  static bool IsTagNameStreamable(const char* tag);
  static void Init();
  static void Cleanup();

 private:
  static Mutex* subscribed_tags_lock_;
  static MallocGrowableArray<const char*> subscribed_tags_;
};

}  // namespace dart

#endif  // RUNTIME_VM_TAGS_H_
