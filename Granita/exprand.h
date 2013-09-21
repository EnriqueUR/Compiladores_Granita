#ifndef EXPRAND_H
#define EXPRAND_H
#include "binaryexpr.h"
class exprAnd:public binaryExpr
{
public:
    exprAnd(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRAND_H
