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

#ifndef CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_MANAGER_H_
#define CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_MANAGER_H_

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Tooling/Core/Replacement.h"
#include "cpp_interop/cpp_refactoring/matcher.h"

namespace Code {

    // Manages registration of AST matchers.
    class MatcherManager {
    public:
        explicit MatcherManager(Matcher::ReplacementMap* in_replacements)
            : replacements(in_replacements) {}

        // Registers Matcher implementations.
        void Register(std::unique_ptr<MatcherFactory> factory) {
            matchers.push_back(std::make_unique<MatchCallbackWrapper>(
                &finder, std::move(factory), replacements));
        }

        auto GetFinder() -> clang::ast_matchers::MatchFinder* { return &finder; }

    private:
        // Adapts Matcher for use with MatchCallback.
        class MatchCallbackWrapper
            : public clang::ast_matchers::MatchFinder::MatchCallback {
        public:
            explicit MatchCallbackWrapper(clang::ast_matchers::MatchFinder* finder,
                std::unique_ptr<MatcherFactory> in_factory,
                Matcher::ReplacementMap* in_replacements)
                : factory(std::move(in_factory)), replacements(in_replacements) {
                factory->AddMatcher(finder, this);
            }

            void run(const clang::ast_matchers::MatchFinder::MatchResult& match_result)
                override {
                factory->CreateMatcher(&match_result, replacements)->Run();
            }

        private:
            std::unique_ptr<MatcherFactory> factory;
            Matcher::ReplacementMap* const replacements;
        };

        Matcher::ReplacementMap* const replacements;
        clang::ast_matchers::MatchFinder finder;
        std::vector<std::unique_ptr<MatcherFactory>> factories;
        std::vector<std::unique_ptr<MatchCallbackWrapper>> matchers;
    };

}  // namespace Code

#endif  // CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_MANAGER_H_