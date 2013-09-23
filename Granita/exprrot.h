#ifndef EXPRROT_H
#define EXPRROT_H
#include "binaryexpr.h"
#include "newexprrot.h"
#include "newexpression.h"

class exprRot:public binaryExpr
{
public:
    exprRot(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRROT_H
