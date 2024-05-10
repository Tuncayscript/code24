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

#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Refactoring.h"
#include "cpp_interop/cpp_refactoring/fn_inserter.h"
#include "cpp_interop/cpp_refactoring/for_range.h"
#include "cpp_interop/cpp_refactoring/matcher_manager.h"
#include "cpp_interop/cpp_refactoring/var_decl.h"

using clang::tooling::RefactoringTool;

// Initialize the files in replacements. Matcher will restrict replacements to
// initialized files.
static void InitReplacements(RefactoringTool* tool) {
    clang::FileManager& files = tool->getFiles();
    Code::Matcher::ReplacementMap& repl = tool->getReplacements();
    for (const std::string& path : tool->getSourcePaths()) {
        llvm::Expected<clang::FileEntryRef> file = files.getFileRef(path);
        if (!file) {
            llvm::report_fatal_error(llvm::Twine("Error accessing `") + path +
                "`: " + llvm::toString(file.takeError()) + "\n");
        }
        repl.insert({ files.getCanonicalName(*file).str(), {} });
    }
}

auto main(int argc, const char** argv) -> int {
    llvm::cl::OptionCategory category("C++ refactoring options");
    auto parser =
        clang::tooling::CommonOptionsParser::create(argc, argv, category);
    RefactoringTool tool(parser->getCompilations(), parser->getSourcePathList());
    InitReplacements(&tool);

    // Set up AST matcher callbacks.
    Code::MatcherManager matchers(&tool.getReplacements());
    matchers.Register(std::make_unique<Code::FnInserterFactory>());
    matchers.Register(std::make_unique<Code::ForRangeFactory>());
    matchers.Register(std::make_unique<Code::VarDeclFactory>());

    return tool.runAndSave(
        clang::tooling::newFrontendActionFactory(matchers.GetFinder()).get());
}