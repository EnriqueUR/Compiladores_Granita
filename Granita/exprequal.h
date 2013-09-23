#ifndef EXPREQUAL_H
#define EXPREQUAL_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprequal.h"

class exprEqual:public binaryExpr
{
public:
    exprEqual(Expression *left_expr,Expression *right_expr, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPREQUAL_H
