/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Filename: ffi.c
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Friday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 
// Purpose: Foreign Function Interface (FFI) Support for Language

#include <iostream>
#include <julia/julia.h>

extern "C" {

void make_twice_ptr(int n, float *p) {
  for (int i = 0; i < n; ++i) {
    p[i] *= 2.0;
  }
}

void make_twice_array(jl_value_t *ptr) {
  if (jl_is_array(ptr) == 0) {
    std::cerr << "This is not an array." << std::endl;
    return; // Error handling
  }
  auto array = reinterpret_cast<jl_array_t *>(ptr);

  std::clog << "length   : " << array->length << std::endl;
  std::clog << "nrows    : " << array->nrows << std::endl;
  std::clog << "elsize   : " << array->elsize << std::endl;

  if (array->flags.ndims != 1) {
    std::cerr << "Only 1D arrays are supported." << std::endl;
    return; // Error handling
  }


  float *data = reinterpret_cast<float *>(array->data);

  for (size_t i = 0; i < array->length; ++i) {
    data[i] *= 2.0;
  }

  auto flags = array->flags;
  std::clog << "how      : " << flags.how << std::endl;
  std::clog << "ndims    : " << flags.ndims << std::endl;
  std::clog << "pooled   : " << flags.pooled << std::endl;
  std::clog << "ptrarray : " << flags.ptrarray << std::endl;
  std::clog << "isshared : " << flags.isshared << std::endl;
  std::clog << "isaligned: " << flags.isaligned << std::endl;
  // TODO check ndim
}
} // extern C
