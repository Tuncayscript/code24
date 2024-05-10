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

#ifndef RUNTIME_VM_URI_H_
#define RUNTIME_VM_URI_H_

#include "platform/utils.h"
#include "src/globals.h"

namespace Code {

struct ParsedUri {
  const char* scheme;
  const char* userinfo;
  const char* host;
  const char* port;
  const char* path;
  const char* query;
  const char* fragment;
};

// Parses a uri into its parts.  Returns false if the parse fails.
bool ParseUri(const char* uri, ParsedUri* parsed_uri);

// Resolves some reference uri with respect to a base uri.
bool ResolveUri(const char* ref_uri,
                const char* base_uri,
                const char** target_uri);

}  // namespace dart

#endif  // RUNTIME_VM_URI_H_
