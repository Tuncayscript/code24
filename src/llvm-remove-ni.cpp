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

#include "llvm-version.h"
#include "passes.h"

#include <llvm/Pass.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Support/Debug.h>

#include "code.h"

#define DEBUG_TYPE "remove_ni"

using namespace llvm;

namespace {

static bool removeNI(Module &M) LANGUAGE_NOTSAFEPOINT
{
    auto dlstr = M.getDataLayoutStr();
    auto nistart = dlstr.find("-ni:");
    if (nistart == std::string::npos)
        return false;
    auto len = dlstr.size();
    auto niend = nistart + 1;
    for (; niend < len; niend++) {
        if (dlstr[niend] == '-') {
            break;
        }
    }
    dlstr.erase(nistart, niend - nistart);
    M.setDataLayout(dlstr);
    return true;
}
}

PreservedAnalyses RemoveNIPass::run(Module &M, ModuleAnalysisManager &AM)
{
    if (removeNI(M)) {
        return PreservedAnalyses::allInSet<CFGAnalyses>();
    }
    return PreservedAnalyses::all();
}
