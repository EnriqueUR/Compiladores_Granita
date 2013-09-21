#ifndef EXPRSHIFTRIGHT_H
#define EXPRSHIFTRIGHT_H
#include "binaryexpr.h"
class exprShiftRight:public binaryExpr
{
public:
    exprShiftRight();
    exprShiftRight(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRSHIFTRIGHT_H
