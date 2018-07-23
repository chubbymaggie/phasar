/******************************************************************************
 * Copyright (c) 2017 Philipp Schubert.
 * All rights reserved. This program and the accompanying materials are made
 * available under the terms of LICENSE.txt.
 *
 * Contributors:
 *     Philipp Schubert and others
 *****************************************************************************/

/*
 * MyVisitor.hh
 *
 *  Created on: 10.06.2016
 *      Author: pdschbrt
 */

#pragma once

#include <clang/AST/RecursiveASTVisitor.h>

namespace clang {
  class Rewriter;
  class VarDecl;
  class TypeDecl;
  class Stmt;
  class FunctionDecl;
}

namespace psr {

// #include <random>
// #include <iostream>
//
// std::random_device rd;
// std::mt19937_64 mt(rd());
// std::uniform_int_distribution<int> dist(0, 2);
// for (int i = 0; i < 10; ++i) {
//   std::cout << dist(mt) << ' ';
// }
// std::cout << '\n';

class RandomChangeVisitor
    : public clang::RecursiveASTVisitor<RandomChangeVisitor> {
private:
  clang::Rewriter &RW;

public:
  RandomChangeVisitor(clang::Rewriter &R);
  virtual bool VisitVarDecl(clang::VarDecl *V);
  virtual bool VisitTypeDecl(clang::TypeDecl *T);
  virtual bool VisitStmt(clang::Stmt *S);
  virtual bool VisitFunctionDecl(clang::FunctionDecl *F);
};

} // namespace psr
