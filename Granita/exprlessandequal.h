#ifndef EXPRLESSANDEQUAL_H
#define EXPRLESSANDEQUAL_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprlessandequal.h"

class exprLessAndEqual:public binaryExpr
{
public:
    exprLessAndEqual(Expression *left_expr,Expression *right_expr, int linea);
    newExpression* ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRLESSANDEQUAL_H
