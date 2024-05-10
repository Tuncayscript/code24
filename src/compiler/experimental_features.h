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

#ifndef RUNTIME_VM_EXPERIMENTAL_FEATURES_H_
#define RUNTIME_VM_EXPERIMENTAL_FEATURES_H_

namespace Code {

enum class ExperimentalFeature {
  inference_update_3,
  inline_class,
  inference_update_2,
  sealed_class,
  class_modifiers,
  records,
  patterns,
  unnamed_libraries,
  inference_update_1,
  enhanced_enums,
  named_arguments_anywhere,
  super_parameters,
  constructor_tearoffs,
  generic_metadata,
  triple_shift,
  nonfunction_type_aliases,
  non_nullable,
  extension_methods,
  constant_update_2018,
  control_flow_collections,
  set_literals,
  spread_collections,
};

bool GetExperimentalFeatureDefault(ExperimentalFeature feature);
const char* GetExperimentalFeatureName(ExperimentalFeature feature);

}  // namespace dart

#endif  // RUNTIME_VM_EXPERIMENTAL_FEATURES_H_
