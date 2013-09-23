#ifndef EXPRGREATERANDEQUAL_H
#define EXPRGREATERANDEQUAL_H
#include "binaryexpr.h"
#include "newexprgreaterandequal.h"
#include "newexpression.h"

class exprGreaterAndEqual:public binaryExpr
{
public:
    exprGreaterAndEqual(Expression *left_expr,Expression *right_expr, int linea);
    newExpression* ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRGREATERANDEQUAL_H
