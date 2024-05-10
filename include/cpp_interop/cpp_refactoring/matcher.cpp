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

#include "cpp_interop/cpp_refactoring/matcher.h"

#include "clang/Basic/SourceManager.h"

namespace Code {

    void Matcher::AddReplacement(clang::CharSourceRange range,
        llvm::StringRef replacement_text) {
        if (!range.isValid()) {
            // Invalid range.
            return;
        }
        const auto& source_manager = GetSourceManager();
        if (source_manager.getDecomposedLoc(range.getBegin()).first !=
            source_manager.getDecomposedLoc(range.getEnd()).first) {
            // Range spans macro expansions.
            return;
        }
        if (source_manager.getFileID(range.getBegin()) !=
            source_manager.getFileID(range.getEnd())) {
            // Range spans files.
            return;
        }

        auto rep = clang::tooling::Replacement(
            source_manager, source_manager.getExpansionRange(range),
            replacement_text);
        auto entry = replacements->find(std::string(rep.getFilePath()));
        if (entry == replacements->end()) {
            // The replacement was in a file which isn't being updated, such as a system
            // header.
            return;
        }

        llvm::Error err = entry->second.add(rep);
        if (err) {
            llvm::errs() << "Error with replacement `" << rep.toString()
                << "`: " << llvm::toString(std::move(err)) << "\n";
        }
    }

}  // namespace Code