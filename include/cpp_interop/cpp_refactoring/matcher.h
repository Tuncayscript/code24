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

#ifndef CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_H_
#define CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_H_

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Lex/Lexer.h"
#include "clang/Tooling/Core/Replacement.h"

namespace Code {

    // This is an abstract class with helpers to make it easier to write matchers.
    // Note a MatcherFactory (below) is also typically required.
    class Matcher {
    public:
        using ReplacementMap = std::map<std::string, clang::tooling::Replacements>;

        Matcher(const clang::ast_matchers::MatchFinder::MatchResult* in_match_result,
            ReplacementMap* in_replacements)
            : match_result(in_match_result), replacements(in_replacements) {}
        virtual ~Matcher() = default;

        // Performs main execution of the matcher when a result is found.
        virtual void Run() = 0;

    protected:
        // Replaces the given range with the specified text.
        void AddReplacement(clang::CharSourceRange range,
            llvm::StringRef replacement_text);

        // Returns a matched node by ID, exiting if not present.
        template <typename NodeType>
        auto GetNodeAsOrDie(llvm::StringRef id) -> const NodeType& {
            auto* node = match_result->Nodes.getNodeAs<NodeType>(id);
            if (!node) {
                llvm::report_fatal_error(std::string("getNodeAs failed for ") + id);
            }
            return *node;
        }

        // Returns the language options.
        auto GetLangOpts() -> const clang::LangOptions& {
            return match_result->Context->getLangOpts();
        }

        // Returns the full source manager.
        auto GetSourceManager() -> const clang::SourceManager& {
            return *match_result->SourceManager;
        }

        // Returns the source text for a given range.
        auto GetSourceText(clang::CharSourceRange range) -> llvm::StringRef {
            return clang::Lexer::getSourceText(range, GetSourceManager(),
                GetLangOpts());
        }

    private:
        const clang::ast_matchers::MatchFinder::MatchResult* const match_result;
        ReplacementMap* const replacements;
    };

    // A factory used to instantiate per-MatchResult Matchers, to be registered with
    // the MatcherManager.
    class MatcherFactory {
    public:
        virtual ~MatcherFactory() = default;

        virtual auto CreateMatcher(
            const clang::ast_matchers::MatchFinder::MatchResult* match_result,
            Matcher::ReplacementMap* replacements) -> std::unique_ptr<Matcher> = 0;

        // Adds the Matcher to the finder with the provided callback.
        virtual void AddMatcher(
            clang::ast_matchers::MatchFinder* finder,
            clang::ast_matchers::MatchFinder::MatchCallback* callback) = 0;
    };

    // A convenience factory that implements CreateMatcher for Matchers that have a
    // standard constructor.
    template <typename MatcherType>
    class MatcherFactoryBase : public MatcherFactory {
    public:
        auto CreateMatcher(
            const clang::ast_matchers::MatchFinder::MatchResult* match_result,
            Matcher::ReplacementMap* replacements)
            -> std::unique_ptr<Matcher> override {
            return std::make_unique<MatcherType>(match_result, replacements);
        }
    };

}  // namespace Code

#endif  // CODE_CPP_INTEROP_CPP_REFACTORING_MATCHER_H_