#ifndef EXPRMODE_H
#define EXPRMODE_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprmode.h"

class exprMode:public binaryExpr
{
public:
    exprMode(Expression *left_expr,Expression *right_expr, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);

};

#endif // EXPRMODE_H
