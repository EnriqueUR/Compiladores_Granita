#ifndef EXPRAND_H
#define EXPRAND_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprand.h"

class exprAnd:public binaryExpr
{
public:
    exprAnd(Expression *left_expr,Expression *right_expr,int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRAND_H
