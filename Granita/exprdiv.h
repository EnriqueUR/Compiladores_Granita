#ifndef EXPRDIV_H
#define EXPRDIV_H
#include "binaryexpr.h"
#include "newexprdiv.h"
#include "newexpression.h"

class exprDiv:public binaryExpr
{
public:
    exprDiv(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRDIV_H
