#ifndef EXPRSUB_H
#define EXPRSUB_H
#include "binaryexpr.h"
class exprSub:public binaryExpr
{
public:
    exprSub();
    exprSub(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRSUB_H
