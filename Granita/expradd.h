#ifndef EXPRADD_H
#define EXPRADD_H
#include "binaryexpr.h"
#include "newexpradd.h"

class exprAdd:public binaryExpr
{
public:
    exprAdd(Expression *left_expr,Expression *right_expr,int linea);
    newExpression* ValidarSermantica();
    void print();
    void PrintError(string msj);
};

#endif // EXPRADD_H
