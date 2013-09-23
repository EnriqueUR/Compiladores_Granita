#ifndef EXPRLESSTHAN_H
#define EXPRLESSTHAN_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprlessthan.h"

class exprLessThan:public binaryExpr
{
public:
    exprLessThan(Expression *left_expr,Expression *right_expr, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRLESSTHAN_H
