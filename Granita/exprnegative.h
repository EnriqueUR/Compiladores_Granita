#ifndef EXPRNEGATIVE_H
#define EXPRNEGATIVE_H
#include "unaryexpr.h"
#include "newexpression.h"
#include "newexprnegative.h"

class exprNegative:public unaryExpr
{
public:
    exprNegative(Expression *expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRNEGATIVE_H
