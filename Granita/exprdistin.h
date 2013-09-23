#ifndef EXPRDISTIN_H
#define EXPRDISTIN_H
#include "binaryexpr.h"
#include "newexprdistin.h"
#include "newexpression.h"

class exprDistin:public binaryExpr
{
public:
    exprDistin(Expression *left_expr,Expression *right_expr, int linea);
    newExpression* ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRDISTIN_H
