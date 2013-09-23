#ifndef EXPRMULT_H
#define EXPRMULT_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprmult.h"

class exprMult:public binaryExpr
{
public:
    exprMult(Expression *left_expr,Expression *right_expr, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRMULT_H
