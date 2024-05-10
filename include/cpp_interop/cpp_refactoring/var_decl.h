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

#ifndef CODE_CPP_INTEROP_CPP_REFACTORING_VAR_DECL_H_
#define CODE_CPP_INTEROP_CPP_REFACTORING_VAR_DECL_H_

#include "cpp_interop/cpp_refactoring/matcher.h"

namespace Code {

    // Updates variable declarations for `var name: type`.
    class VarDecl : public Matcher {
    public:
        using Matcher::Matcher;
        void Run() override;

    private:
        auto GetTypeStr(const clang::VarDecl& decl) -> std::string;
    };

    class VarDeclFactory : public MatcherFactoryBase<VarDecl> {
    public:
        void AddMatcher(
            clang::ast_matchers::MatchFinder* finder,
            clang::ast_matchers::MatchFinder::MatchCallback* callback) override;
    };

}  // namespace Code

#endif  // CODE_CPP_INTEROP_CPP_REFACTORING_VAR_DECL_H_