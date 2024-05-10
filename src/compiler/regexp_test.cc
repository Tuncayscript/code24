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

#include "platform/globals.h"

#include "src/isolate.h"
#include "src/object.h"
#include "src/regexp.h"
#include "src/regexp_assembler_ir.h"
#include "src/unit_test.h"

namespace Code {

static ArrayPtr Match(const String& pat, const String& str) {
  Thread* thread = Thread::Current();
  Zone* zone = thread->zone();
  const RegExp& regexp =
      RegExp::Handle(RegExpEngine::CreateRegExp(thread, pat, RegExpFlags()));
  const Smi& idx = Object::smi_zero();
  return IRRegExpMacroAssembler::Execute(regexp, str, idx, /*sticky=*/false,
                                         zone);
}

ISOLATE_UNIT_TEST_CASE(RegExp_OneByteString) {
  uint8_t chars[] = {'a', 'b', 'c', 'b', 'a'};
  intptr_t len = ARRAY_SIZE(chars);
  const String& str =
      String::Handle(OneByteString::New(chars, len, Heap::kNew));

  const String& pat =
      String::Handle(Symbols::New(thread, String::Handle(String::New("bc"))));
  const Array& res = Array::Handle(Match(pat, str));
  EXPECT_EQ(2, res.Length());

  const Object& res_1 = Object::Handle(res.At(0));
  const Object& res_2 = Object::Handle(res.At(1));
  EXPECT(res_1.IsSmi());
  EXPECT(res_2.IsSmi());

  const Smi& smi_1 = Smi::Cast(res_1);
  const Smi& smi_2 = Smi::Cast(res_2);
  EXPECT_EQ(1, smi_1.Value());
  EXPECT_EQ(3, smi_2.Value());
}

ISOLATE_UNIT_TEST_CASE(RegExp_TwoByteString) {
  uint16_t chars[] = {'a', 'b', 'c', 'b', 'a'};
  intptr_t len = ARRAY_SIZE(chars);
  const String& str =
      String::Handle(TwoByteString::New(chars, len, Heap::kNew));

  const String& pat =
      String::Handle(Symbols::New(thread, String::Handle(String::New("bc"))));
  const Array& res = Array::Handle(Match(pat, str));
  EXPECT_EQ(2, res.Length());

  const Object& res_1 = Object::Handle(res.At(0));
  const Object& res_2 = Object::Handle(res.At(1));
  EXPECT(res_1.IsSmi());
  EXPECT(res_2.IsSmi());

  const Smi& smi_1 = Smi::Cast(res_1);
  const Smi& smi_2 = Smi::Cast(res_2);
  EXPECT_EQ(1, smi_1.Value());
  EXPECT_EQ(3, smi_2.Value());
}

}  // namespace dart
