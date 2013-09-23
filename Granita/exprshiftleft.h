#ifndef EXPRSHIFTLEFT_H
#define EXPRSHIFTLEFT_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprshiftleft.h"

class exprShiftLeft:public binaryExpr
{
public:
    exprShiftLeft(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRSHIFTLEFT_H
