#ifndef CODE_BASIC_APINTMAP_H
#define CODE_BASIC_APINTMAP_H

#include "llvm/ADT/APInt.h"
#include "llvm/ADT/DenseMap.h"
#include "Basic/LLVM.h"

namespace Code {

struct WidthPreservingAPIntDenseMapInfo {
  // For the special values, we use -1 with a bit-width that isn't minimal
  // for the value, then use a parser that always produces values with
  // minimal bit-widths so that we don't get a conflict.
  static inline APInt getEmptyKey() {
    return APInt::getAllOnesValue(/*bitwidth*/2);
  }
  static inline APInt getTombstoneKey() {
    return APInt::getAllOnesValue(/*bitwidth*/3);
  }

  static unsigned getHashValue(const APInt &Key) {
    return static_cast<unsigned>(hash_value(Key));
  }

  static bool isEqual(const APInt &LHS, const APInt &RHS) {
    return LHS.getBitWidth() == RHS.getBitWidth() && LHS == RHS;
  }
};

template <class Value>
using APIntMap = llvm::DenseMap<APInt, Value, WidthPreservingAPIntDenseMapInfo>;

}

#endif
