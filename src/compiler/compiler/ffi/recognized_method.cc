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

#include "src/compiler/ffi/recognized_method.h"

#include "src/symbols.h"

namespace Code {

namespace compiler {

namespace ffi {

classid_t ElementTypedDataCid(classid_t class_id) {
  switch (class_id) {
    case kFfiInt8Cid:
      return kTypedDataInt8ArrayCid;
    case kFfiUint8Cid:
      return kTypedDataUint8ArrayCid;
    case kFfiInt16Cid:
      return kTypedDataInt16ArrayCid;
    case kFfiUint16Cid:
      return kTypedDataUint16ArrayCid;
    case kFfiInt32Cid:
      return kTypedDataInt32ArrayCid;
    case kFfiUint32Cid:
      return kTypedDataUint32ArrayCid;
    case kFfiInt64Cid:
      return kTypedDataInt64ArrayCid;
    case kFfiUint64Cid:
      return kTypedDataUint64ArrayCid;
    case kPointerCid:
      return target::kWordSize == 4 ? kTypedDataUint32ArrayCid
                                    : kTypedDataUint64ArrayCid;
    case kFfiFloatCid:
      return kTypedDataFloat32ArrayCid;
    case kFfiDoubleCid:
      return kTypedDataFloat64ArrayCid;
    default:
      UNREACHABLE();
  }
}

classid_t ElementExternalTypedDataCid(classid_t class_id) {
  switch (class_id) {
    case kFfiInt8Cid:
      return kExternalTypedDataInt8ArrayCid;
    case kFfiUint8Cid:
      return kExternalTypedDataUint8ArrayCid;
    case kFfiInt16Cid:
      return kExternalTypedDataInt16ArrayCid;
    case kFfiUint16Cid:
      return kExternalTypedDataUint16ArrayCid;
    case kFfiInt32Cid:
      return kExternalTypedDataInt32ArrayCid;
    case kFfiUint32Cid:
      return kExternalTypedDataUint32ArrayCid;
    case kFfiInt64Cid:
      return kExternalTypedDataInt64ArrayCid;
    case kFfiUint64Cid:
      return kExternalTypedDataUint64ArrayCid;
    case kFfiFloatCid:
      return kExternalTypedDataFloat32ArrayCid;
    case kFfiDoubleCid:
      return kExternalTypedDataFloat64ArrayCid;
    default:
      UNREACHABLE();
  }
}

classid_t RecognizedMethodTypeArgCid(MethodRecognizer::Kind kind) {
  switch (kind) {
#define LOAD_STORE(type)                                                       \
  case MethodRecognizer::kFfiLoad##type:                                       \
  case MethodRecognizer::kFfiStore##type:                                      \
    return kFfi##type##Cid;
    CLASS_LIST_FFI_NUMERIC_FIXED_SIZE(LOAD_STORE)
#undef LOAD_STORE
    case MethodRecognizer::kFfiLoadFloatUnaligned:
    case MethodRecognizer::kFfiStoreFloatUnaligned:
      return kFfiFloatCid;
    case MethodRecognizer::kFfiLoadDoubleUnaligned:
    case MethodRecognizer::kFfiStoreDoubleUnaligned:
      return kFfiDoubleCid;
    case MethodRecognizer::kFfiLoadPointer:
    case MethodRecognizer::kFfiStorePointer:
      return kPointerCid;
#define AS_EXTERNAL_TYPED_DATA(type)                                           \
  case MethodRecognizer::kFfiAsExternalTypedData##type:                        \
    return kFfi##type##Cid;
      CLASS_LIST_FFI_NUMERIC_FIXED_SIZE(AS_EXTERNAL_TYPED_DATA)
#undef AS_EXTERNAL_TYPED_DATA
    default:
      UNREACHABLE();
  }
}

AlignmentType RecognizedMethodAlignment(MethodRecognizer::Kind kind) {
  switch (kind) {
#define LOAD_STORE(type)                                                       \
  case MethodRecognizer::kFfiLoad##type:                                       \
  case MethodRecognizer::kFfiStore##type:                                      \
    return kAlignedAccess;
    CLASS_LIST_FFI_NUMERIC_FIXED_SIZE(LOAD_STORE)
    LOAD_STORE(Pointer)
#undef LOAD_STORE
    case MethodRecognizer::kFfiLoadFloatUnaligned:
    case MethodRecognizer::kFfiStoreFloatUnaligned:
    case MethodRecognizer::kFfiLoadDoubleUnaligned:
    case MethodRecognizer::kFfiStoreDoubleUnaligned:
      return kUnalignedAccess;
    default:
      UNREACHABLE();
  }
}

MethodRecognizer::Kind FfiLoad(const NativeType& native_type) {
  if (native_type.IsPrimitive()) {
    switch (native_type.AsPrimitive().representation()) {
#define CASE(type)                                                             \
  case k##type:                                                                \
    return MethodRecognizer::kFfiLoad##type;
      CLASS_LIST_FFI_NUMERIC_FIXED_SIZE(CASE)
#undef CASE
      default:
        break;
    }
  }
  UNIMPLEMENTED();
}

MethodRecognizer::Kind FfiStore(const NativeType& native_type) {
  if (native_type.IsPrimitive()) {
    switch (native_type.AsPrimitive().representation()) {
#define CASE(type)                                                             \
  case k##type:                                                                \
    return MethodRecognizer::kFfiStore##type;
      CLASS_LIST_FFI_NUMERIC_FIXED_SIZE(CASE)
#undef CASE
      default:
        break;
    }
  }
  UNIMPLEMENTED();
}

}  // namespace ffi

}  // namespace compiler

}  // namespace dart
