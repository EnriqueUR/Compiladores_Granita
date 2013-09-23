#ifndef EXPRSHIFTRIGHT_H
#define EXPRSHIFTRIGHT_H
#include "binaryexpr.h"
#include "newexpression.h"
#include "newexprshiftright.h"

class exprShiftRight:public binaryExpr
{
public:
    exprShiftRight(Expression *left_expr,Expression *right_expr, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);

};

#endif // EXPRSHIFTRIGHT_H
