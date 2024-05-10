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


#include "cpp_interop/rewriter.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "clang/AST/ASTConsumer.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

namespace Code::Testing {
    namespace {

        // Represents C++ source code with at most one region enclosed in $[[...]]$ as
        // an annotated range.
        class Annotations {
        public:
            explicit Annotations(llvm::StringRef annotated_source) {
                size_t index = annotated_source.find("$[[");
                if (index == llvm::StringRef::npos) {
                    source_code_ = std::string(annotated_source);
                    return;
                }
                start_ = index;
                end_ = annotated_source.find("]]$", index);
                CODE_CHECK(end_ != llvm::StringRef::npos)
                    << "Found `$[[` but no matching `]]$`";
                source_code_ = (llvm::Twine(annotated_source.substr(0, start_)) +
                    annotated_source.substr(start_ + 3, end_ - start_ - 3) +
                    annotated_source.substr(end_ + 3))
                    .str();
                // Update `end_` so that it is relative to the unannotated source (which
                // means three characters earlier due to the `$[[` being removed.
                end_ -= 3;
            }

            // Returns a view into the unannotated source.
            auto source() const -> llvm::StringRef { return source_code_; }

            // Returns the offsets in the file representing the annotated range if they
            // exist and `{0, std::numeric_limits<size_t>::max()}` otherwise.
            auto range() const -> std::pair<size_t, size_t> {
                return std::pair(start_, end_);
            }

        private:
            std::string source_code_;
            size_t start_ = 0;
            size_t end_ = std::numeric_limits<size_t>::max();
        };

        // Rewrites the `cpp_code`, return the Code equivalent. If the text has no
        // source range annotated with $[[...]]$, the entire translation unit will be
        // migrated and output. Otherwise, only the migrated output corresponding to the
        // annotated range will be output. No more than one range may be annotated at
        // all.
        //
        // This annotation mechanism is useful in that it allows us to specifically test
        // the migration associated with specific nodes even when they require some
        // additional context that we do not wish to be covered by the test.
        auto RewriteText(llvm::StringRef cpp_code) -> std::string {
            std::string result;

            Annotations annotated_cpp_code(cpp_code);

            bool success = clang::tooling::runToolOnCodeWithArgs(
                std::make_unique<MigrationAction>(result, annotated_cpp_code.range()),
                annotated_cpp_code.source(), {}, "test.cc", "clang-tool",
                std::make_shared<clang::PCHContainerOperations>(),
                clang::tooling::FileContentMappings());

            return success ? result : "";
        }

        TEST(Rewriter, BoolLiteral) {
            EXPECT_EQ(RewriteText("Variable x As Boolean = $[[True]]$"), "True");
            EXPECT_EQ(RewriteText("Variable x As Boolean = $[[False]]$"), "False");
        }
    }  // namespace
}  // namespace Code::Testing