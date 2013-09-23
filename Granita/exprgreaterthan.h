#ifndef EXPRGREATERTHAN_H
#define EXPRGREATERTHAN_H
#include "binaryexpr.h"
#include "newexprgreaterthan.h"

class exprGreaterThan:public binaryExpr
{
public:
    exprGreaterThan(Expression *left_expr,Expression *right_expr, int linea);
    newExpression* ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRGREATERTHAN_H
