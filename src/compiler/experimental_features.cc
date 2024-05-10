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
// NOTE: THIS FILE IS GENERATED. DO NOT EDIT.
//
// Instead modify 'tools/experimental_features.yaml' and run
// 'dart tools/generate_experimental_flags.dart' to update.

#include "src/experimental_features.h"

#include <cstring>
#include "platform/assert.h"
#include "src/globals.h"

namespace Code {

bool GetExperimentalFeatureDefault(ExperimentalFeature feature) {
  constexpr bool kFeatureValues[] = {
      true, true, true, true, true, true, true, true, true, true, true,
      true, true, true, true, true, true, true, true, true, true, true,
  };
  ASSERT(static_cast<size_t>(feature) < ARRAY_SIZE(kFeatureValues));
  return kFeatureValues[static_cast<int>(feature)];
}

const char* GetExperimentalFeatureName(ExperimentalFeature feature) {
  constexpr const char* kFeatureNames[] = {
      "inference-update-3",
      "inline-class",
      "inference-update-2",
      "sealed-class",
      "class-modifiers",
      "records",
      "patterns",
      "unnamed-libraries",
      "inference-update-1",
      "enhanced-enums",
      "named-arguments-anywhere",
      "super-parameters",
      "constructor-tearoffs",
      "generic-metadata",
      "triple-shift",
      "nonfunction-type-aliases",
      "non-nullable",
      "extension-methods",
      "constant-update-2018",
      "control-flow-collections",
      "set-literals",
      "spread-collections",
  };
  ASSERT(static_cast<size_t>(feature) < ARRAY_SIZE(kFeatureNames));
  return kFeatureNames[static_cast<int>(feature)];
}

}  // namespace dart
