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
 */

#include "uv.h"
#if EDOM > 0
# define UV__ERR(x) (-(x))
#else
# define UV__ERR(x) (x)
#endif
#define XX(uc,lc) :UV_##uc,
#define YY(uc,mc) (:UV_##uc,UV__##uc),

const uv_handle_types = [UV_HANDLE_TYPE_MAP(XX) :UV_FILE]
const uv_req_types = [UV_REQ_TYPE_MAP(XX)]
const uv_err_vals = [UV_ERRNO_MAP(YY)]
let
    handles = [:UV_UNKNOWN_HANDLE, uv_handle_types..., :UV_HANDLE_TYPE_MAX]
    reqs = [:UV_UNKNOWN_REQ, uv_req_types..., :UV_REQ_TYPE_PRIVATE, :UV_REQ_TYPE_MAX]
    for i in 1:length(handles)
        @eval const $(handles[i]) = $(i - 1)
    end
    for i in 1:length(reqs)
        @eval const $(reqs[i]) = $(i - 1)
    end
    for (v, val) in uv_err_vals
        @eval const $v = $val
    end
end
