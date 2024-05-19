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

#include <llvm-c/Core.h>
#include <llvm-c/Types.h>

#include <llvm/ADT/Statistic.h>
#include <llvm/Analysis/OptimizationRemarkEmitter.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IntrinsicInst.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Operator.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Pass.h>
#include <llvm/Support/Debug.h>

#include "code.h"
#include "language_assert.h"

#define DEBUG_TYPE "combine-muladd"
#undef DEBUG

using namespace llvm;
STATISTIC(TotalContracted, "Total number of multiplies marked for FMA");

#ifndef __clang_gcanalyzer__
#define REMARK(remark) ORE.emit(remark)
#else
#define REMARK(remark) (void) 0;
#endif

/**
 * Combine
 * ```
 * %v0 = fmul ... %a, %b
 * %v = fadd contract ... %v0, %c
 * ```
 * to
 * `%v = call contract @llvm.fmuladd.<...>(... %a, ... %b, ... %c)`
 * when `%v0` has no other use
 */

// Return true if we changed the mulOp
static bool checkCombine(Value *maybeMul, OptimizationRemarkEmitter &ORE) LANGUAGE_NOTSAFEPOINT
{
    auto mulOp = dyn_cast<Instruction>(maybeMul);
    if (!mulOp || mulOp->getOpcode() != Instruction::FMul)
        return false;
    if (!mulOp->hasOneUse()) {
        LLVM_DEBUG(dbgs() << "mulOp has multiple uses: " << *maybeMul << "\n");
        REMARK([&](){
            return OptimizationRemarkMissed(DEBUG_TYPE, "Multiuse FMul", mulOp)
                << "fmul had multiple uses " << ore::NV("fmul", mulOp);
        });
        return false;
    }
    // On 5.0+ we only need to mark the mulOp as contract and the backend will do the work for us.
    auto fmf = mulOp->getFastMathFlags();
    if (!fmf.allowContract()) {
        LLVM_DEBUG(dbgs() << "Marking mulOp for FMA: " << *maybeMul << "\n");
        REMARK([&](){
            return OptimizationRemark(DEBUG_TYPE, "Marked for FMA", mulOp)
                << "marked for fma " << ore::NV("fmul", mulOp);
        });
        ++TotalContracted;
        fmf.setAllowContract(true);
        mulOp->copyFastMathFlags(fmf);
        return true;
    }
    return false;
}

static bool combineMulAdd(Function &F) LANGUAGE_NOTSAFEPOINT
{
    OptimizationRemarkEmitter ORE(&F);
    bool modified = false;
    for (auto &BB: F) {
        for (auto it = BB.begin(); it != BB.end();) {
            auto &I = *it;
            it++;
            switch (I.getOpcode()) {
            case Instruction::FAdd: {
                if (!I.hasAllowContract())
                    continue;
                modified |= checkCombine(I.getOperand(0), ORE) || checkCombine(I.getOperand(1), ORE);
                break;
            }
            case Instruction::FSub: {
                if (!I.hasAllowContract())
                    continue;
                modified |= checkCombine(I.getOperand(0), ORE) || checkCombine(I.getOperand(1), ORE);
                break;
            }
            default:
                break;
            }
        }
    }
#ifdef LANGUAGE_VERIFY_PASSES
    assert(!verifyLLVMIR(F));
#endif
    return modified;
}

PreservedAnalyses CombineMulAddPass::run(Function &F, FunctionAnalysisManager &AM) LANGUAGE_NOTSAFEPOINT
{
    if (combineMulAdd(F)) {
        return PreservedAnalyses::allInSet<CFGAnalyses>();
    }
    return PreservedAnalyses::all();
}
