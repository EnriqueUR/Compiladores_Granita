#ifndef EXPROR_H
#define EXPROR_H
#include "binaryexpr.h"
#include "newexpror.h"
#include "newexpression.h"

class ExprOr:public binaryExpr
{
public:
    ExprOr(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPROR_H
