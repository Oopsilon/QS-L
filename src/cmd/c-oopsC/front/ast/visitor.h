/* Oopsilon Static Compiler (Oopsilon)
 * AST visitor.
 * Copyright (c) 2017 D. Mackay. All rights reserved. */

#pragma once

#include "ast.h"
#include "class.h"
#include "clsProto.h"
#include "expr.h"
#include "field.h"
#include "method.h"
#include "protocol.h"
#include "typeRepr.h"

namespace AST
{

struct Visitor
{
    /* Basic node */
    virtual void visitNode (AST & aNode);

    /* Symbols */
    virtual void visitSymbol (Symbol & aNode);

    /* Fields */
    virtual void visitField (Field & aNode);
    /*virtual void visitClassField (ClassField & aNode);
    virtual void visitIVarField (IVarField & aNode);
    virtual void visitCVarField (CVarField & aNode);
    virtual void visitArgField (ArgField & aNode);
    virtual void visitLocalField (LocalField & aNode);*/

    /* Expressions */
    virtual void visitExpr (Expr & aNode);
    virtual void visitIdentExpr (IdentExpr & aNode);
    virtual void visitLiteralExpr (LiteralExpr & aNode);
    virtual void visitReturnExpr (ReturnExpr & aNode);
    virtual void visitMsgExpr (MsgExpr & aNode);
    virtual void visitBlockExpr (BlockExpr & aNode);

    /* Code */
    virtual void visitMethodBlockCommon (MethodBlockCommon & aNode);

    /* Program */
    virtual void visitProgram (Program & aNode);

    /* Directives */
    virtual void visitClassLike (ClassProtocolCommon & aNode);
    virtual void visitClass (Class & aNode);
    virtual void visitProtocol (Protocol & aNode);

    /* Class members */
    virtual void visitMethod (Method & aNode);

    /* Type reprs */
    /*virtual void visitTypeRepr (TypeRepr & aNode);
    virtual void visitIdTypeRepr (IdTypeRepr & aNode);
    virtual void visitSelfTypeRepr (SelfTypeRepr & aNode);
    virtual void visitInstanceTypeRepr (InstanceTypeRepr & aNode);
    virtual void visitClassTypeRepr (ClassTypeRepr & aNode);
    virtual void visitNilTypeRepr (NilTypeRepr & aNode);
    virtual void visitNamedTypeRepr (NamedTypeRepr & aNode);
    virtual void visitPlaceholderTypeRepr (PlaceholderTypeRepr & aNode);
    virtual void
    visitParameterisedTypeReprDecl (ParameterisedTypeReprDecl & aNode);
    virtual void visitTypeInvocationRepr (TypeInvocationRepr & aNode);
    // virtual void visitTypeProtQualRepr (TypeProtQualRepr & aNode);
    virtual void visitSumTypeRepr (SumTypeRepr & aNode);
    virtual void visitBlockTypeRepr (BlockTypeRepr & aNode*/
};
} // namespace AST
