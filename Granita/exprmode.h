#ifndef EXPRMODE_H
#define EXPRMODE_H
#include "binaryexpr.h"
class exprMode:public binaryExpr
{
public:
    exprMode();
    exprMode(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRMODE_H
