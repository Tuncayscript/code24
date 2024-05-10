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

#include "cpp_interop/cpp_refactoring/fn_inserter.h"

#include "clang/ASTMatchers/ASTMatchers.h"

namespace cam = ::clang::ast_matchers;

namespace Code {

    static constexpr char Label[] = "FnInserter";

    void FnInserter::Run() {
        const auto& decl = GetNodeAsOrDie<clang::FunctionDecl>(Label);

        // For names like "Class::Method", replace up to "Class" not "Method".
        clang::NestedNameSpecifierLoc qual_loc = decl.getQualifierLoc();
        clang::SourceLocation name_begin_loc =
            qual_loc.hasQualifier() ? qual_loc.getBeginLoc() : decl.getLocation();
        auto range =
            clang::CharSourceRange::getCharRange(decl.getBeginLoc(), name_begin_loc);

        // In order to handle keywords like "virtual" in "virtual auto Foo() -> ...",
        // scan the replaced text and only drop auto/void entries.
        llvm::SmallVector<llvm::StringRef> split;
        GetSourceText(range).split(split, ' ', /*MaxSplit=*/-1, /*KeepEmpty=*/false);
        std::string new_text = "fn ";
        for (llvm::StringRef t : split) {
            if (t != "auto" && t != "void") {
                new_text += t.str() + " ";
            }
        }
        AddReplacement(range, new_text);
    }

    void FnInserterFactory::AddMatcher(cam::MatchFinder* finder,
        cam::MatchFinder::MatchCallback* callback) {
        finder->addMatcher(
            cam::functionDecl(cam::anyOf(cam::hasTrailingReturn(),
                cam::returns(cam::asString("void"))),
                cam::unless(cam::anyOf(cam::cxxConstructorDecl(),
                    cam::cxxDestructorDecl())))
            .bind(Label),
            callback);
    }

}  // namespace Code