/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
//             Tural Ghuliev (turalquliyev@it-gss.com)
// Date: Monday, June 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#include <mutex>
#include <condition_variable>
#include <llvm/ADT/DenseMap.h>
#include <llvm/ADT/DenseSet.h>
#include <llvm/ADT/SmallVector.h>
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

using namespace llvm;

struct ReservationInfo {
    int16_t tid = 0;
    language_code_instance_t *ci = nullptr;
};

struct InferKey {
    language_method_instance_t *mi = nullptr;
    language_value_t *owner = nullptr;
};

template<> struct llvm::DenseMapInfo<InferKey> {
  using FirstInfo = DenseMapInfo<language_method_instance_t*>;
  using SecondInfo = DenseMapInfo<language_value_t*>;

  static inline InferKey getEmptyKey() {
    return InferKey{FirstInfo::getEmptyKey(),
                    SecondInfo::getEmptyKey()};
  }

  static inline InferKey getTombstoneKey() {
    return InferKey{FirstInfo::getTombstoneKey(),
                    SecondInfo::getTombstoneKey()};
  }

  static unsigned getHashValue(const InferKey& PairVal) {
    return detail::combineHashValue(FirstInfo::getHashValue(PairVal.mi),
                                    SecondInfo::getHashValue(PairVal.owner));
  }

  static bool isEqual(const InferKey &LHS, const InferKey &RHS) {
    return LHS.mi == RHS.mi && LHS.owner == RHS.owner;
  }
};

static std::mutex engine_lock;
static std::condition_variable engine_wait;
// map from MethodInstance to threadid that owns it currently for inference
static DenseMap<InferKey, ReservationInfo> Reservations;
// vector of which threads are blocked and which lease they need
static SmallVector<InferKey, 0> Awaiting; // (this could be merged into ptls also)


#ifdef __cplusplus
extern "C" {
#endif

language_code_instance_t *language_engine_reserve(language_method_instance_t *m, language_value_t *owner)
{
    language_task_t *ct = language_current_task;
    ct->ptls->engine_nqueued++; // disables finalizers until inference is finished on this method graph
    language_code_instance_t *ci = language_new_codeinst_uninit(m, owner); // allocate a placeholder
    JL_GC_PUSH1(&ci);
    int8_t gc_state = language_gc_safe_enter(ct->ptls);
    InferKey key = {m, owner};
    std::unique_lock<std::mutex> lock(engine_lock);
    auto tid = language_atomic_load_relaxed(&ct->tid);
    if ((signed)Awaiting.size() < tid + 1)
        Awaiting.resize(tid + 1);
    while (1) {
        auto record = Reservations.find(key);
        if (record == Reservations.end()) {
            Reservations[key] = ReservationInfo{tid, ci};
            lock.unlock();
            language_gc_safe_leave(ct->ptls, gc_state); // contains language_gc_safepoint
            JL_GC_POP();
            return ci;
        }
        // before waiting, need to run deadlock/cycle detection
        // there is a cycle if the thread holding our lease is blocked
        // and waiting for (transitively) any lease that is held by this thread
        auto wait_tid = record->second.tid;
        while (1) {
            if (wait_tid == tid) {
                lock.unlock();
                language_gc_safe_leave(ct->ptls, gc_state); // contains language_gc_safepoint
                JL_GC_POP();
                ct->ptls->engine_nqueued--;
                return ci; // break the cycle
            }
            if ((signed)Awaiting.size() <= wait_tid)
                break; // no cycle, since it is running (and this should be unreachable)
            auto key2 = Awaiting[wait_tid];
            if (key2.mi == nullptr)
                break; // no cycle, since it is running
            auto record2 = Reservations.find(key2);
            if (record2 == Reservations.end())
                break; // no cycle, since it is about to resume
            assert(wait_tid != record2->second.tid);
            wait_tid = record2->second.tid;
        }
        Awaiting[tid] = key;
        engine_wait.wait(lock);
        Awaiting[tid] = InferKey{};
    }
}

int language_engine_hasreserved(language_method_instance_t *m, language_value_t *owner)
{
    language_task_t *ct = language_current_task;
    InferKey key = {m, owner};
    std::unique_lock<std::mutex> lock(engine_lock);
    auto record = Reservations.find(key);
    return record != Reservations.end() && record->second.tid == language_atomic_load_relaxed(&ct->tid);
}

STATIC_INLINE int gc_marked(uintptr_t bits) JL_NOTSAFEPOINT
{
    return (bits & GC_MARKED) != 0;
}

void language_engine_sweep(language_ptls_t *gc_all_tls_states)
{
    std::unique_lock<std::mutex> lock(engine_lock);
    bool any = false;
    for (auto I = Reservations.begin(); I != Reservations.end(); ++I) {
        language_code_instance_t *ci = I->second.ci;
        if (!gc_marked(language_astaggedvalue(ci)->bits.gc)) {
            auto tid = I->second.tid;
            Reservations.erase(I);
            language_ptls_t ptls2 = gc_all_tls_states[tid];
            ptls2->engine_nqueued--;
            any = true;
        }
    }
    if (any)
        engine_wait.notify_all();
}

void language_engine_fulfill(language_code_instance_t *ci, language_code_info_t *src)
{
    language_task_t *ct = language_current_task;
    std::unique_lock<std::mutex> lock(engine_lock);
    auto record = Reservations.find(InferKey{ci->def, ci->owner});
    if (record == Reservations.end() || record->second.ci != ci)
        return;
    assert(language_atomic_load_relaxed(&ct->tid) == record->second.tid);
    ct->ptls->engine_nqueued--; // re-enables finalizers, but doesn't immediately try to run them
    Reservations.erase(record);
    engine_wait.notify_all();
}


#ifdef __cplusplus
}
#endif
