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

// Declarations for debuginfo.cpp

int language_DI_for_fptr(uint64_t fptr, uint64_t *symsize, int64_t *slide,
        llvm::object::SectionRef *Section, llvm::DIContext **context) LANGUAGE_NOTSAFEPOINT;

bool language_dylib_DI_for_fptr(size_t pointer, llvm::object::SectionRef *Section, int64_t *slide, llvm::DIContext **context,
    bool onlyImage, bool *isImage, uint64_t* fbase, void **saddr, char **name, char **filename) LANGUAGE_NOTSAFEPOINT;

static object::SectionedAddress makeAddress(
        llvm::object::SectionRef Section, uint64_t address) LANGUAGE_NOTSAFEPOINT
{
    return object::SectionedAddress{address, Section.getIndex()};
}
