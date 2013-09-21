#ifndef EXPRDISTIN_H
#define EXPRDISTIN_H
#include "binaryexpr.h"
class exprDistin:public binaryExpr
{
public:
    exprDistin();
    exprDistin(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRDISTIN_H
