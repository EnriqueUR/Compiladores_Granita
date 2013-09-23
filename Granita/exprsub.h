#ifndef EXPRSUB_H
#define EXPRSUB_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprsub.h"

class exprSub:public binaryExpr
{
public:
    exprSub(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRSUB_H
