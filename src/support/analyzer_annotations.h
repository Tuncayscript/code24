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

#ifndef __has_feature
#define __has_feature(x) 0
#endif
#if !(defined(__clang__) && __has_feature(nullability))
#define _Nonnull
#endif
#define LANGUAGE_NONNULL _Nonnull

#ifdef __clang_gcanalyzer__

#define LANGUAGE_PROPAGATES_ROOT __attribute__((annotate("language_propagates_root")))
#define LANGUAGE_NOTSAFEPOINT __attribute__((annotate("language_not_safepoint")))
#define LANGUAGE_NOTSAFEPOINT_ENTER __attribute__((annotate("language_notsafepoint_enter")))
#define LANGUAGE_NOTSAFEPOINT_LEAVE __attribute__((annotate("language_notsafepoint_leave")))
#define LANGUAGE_MAYBE_UNROOTED __attribute__((annotate("language_maybe_unrooted")))
#define LANGUAGE_GLOBALLY_ROOTED __attribute__((annotate("language_globally_rooted")))
#define LANGUAGE_ROOTING_ARGUMENT __attribute__((annotate("language_rooting_argument")))
#define LANGUAGE_ROOTED_ARGUMENT __attribute__((annotate("language_rooted_argument")))
#define LANGUAGE_GC_DISABLED __attribute__((annotate("language_gc_disabled")))
#define LANGUAGE_ALWAYS_LEAFTYPE LANGUAGE_GLOBALLY_ROOTED
#define LANGUAGE_ROOTS_TEMPORARILY __attribute__((annotate("language_temporarily_roots")))
#define LANGUAGE_REQUIRE_ROOTED_SLOT __attribute__((annotate("language_require_rooted_slot")))
#ifdef __cplusplus
extern "C" {
#endif
  void LANGUAGE_GC_PROMISE_ROOTED(void *v) LANGUAGE_NOTSAFEPOINT;
  void language_may_leak(void *v) LANGUAGE_NOTSAFEPOINT;
#ifdef __cplusplus
}
#endif

#else

#define LANGUAGE_PROPAGATES_ROOT
#define LANGUAGE_NOTSAFEPOINT
#define LANGUAGE_NOTSAFEPOINT_ENTER
#define LANGUAGE_NOTSAFEPOINT_LEAVE
#define LANGUAGE_MAYBE_UNROOTED
#define LANGUAGE_GLOBALLY_ROOTED
#define LANGUAGE_ROOTING_ARGUMENT
#define LANGUAGE_ROOTED_ARGUMENT
#define LANGUAGE_GC_DISABLED
#define LANGUAGE_ALWAYS_LEAFTYPE
#define LANGUAGE_ROOTS_TEMPORARILY
#define LANGUAGE_REQUIRE_ROOTED_SLOT
#define LANGUAGE_GC_PROMISE_ROOTED(x) (void)(x)
#define language_may_leak(x) (void)(x)

#endif
