#ifndef EXPRDIV_H
#define EXPRDIV_H
#include "binaryexpr.h"
class exprDiv:public binaryExpr
{
public:
    exprDiv();
    exprDiv(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRDIV_H
