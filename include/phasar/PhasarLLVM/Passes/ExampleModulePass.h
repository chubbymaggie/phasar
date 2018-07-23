/******************************************************************************
 * Copyright (c) 2017 Philipp Schubert.
 * All rights reserved. This program and the accompanying materials are made
 * available under the terms of LICENSE.txt.
 *
 * Contributors:
 *     Philipp Schubert and others
 *****************************************************************************/

/*
 * MyAliasAnalysis.h
 *
 *  Created on: 07.07.2016
 *      Author: pdschbrt
 */

#pragma once

#include <llvm/Pass.h>
#include <llvm/Analysis/AliasAnalysis.h>

namespace llvm {
  class Module;
  class AnalysisUsage;
}

namespace psr {

//WARNING: Why is llvm::AAResultBase a parent of this pass ?
class ExampleModulePass : public llvm::ModulePass, llvm::AAResultBase<llvm::BasicAAResult> {
public:
  static char ID;
  ExampleModulePass() : llvm::ModulePass(ID) {}
  void getAnalysisUsage(llvm::AnalysisUsage &AU) const override;
  bool doInitialization(llvm::Module &M) override;
  bool runOnModule(llvm::Module &M) override;
  bool doFinalization(llvm::Module &M) override;
  void releaseMemory() override;
  //	void *getAdjustedAnalysisPointer(AnalysisID ID) override;
  //	AliasResult alias(const Value *V1, unsigned V1Size,
  //			  	  	  const Value *V2, unsigned V2Size);
};

} // namespace psr
