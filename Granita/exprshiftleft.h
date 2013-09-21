#ifndef EXPRSHIFTLEFT_H
#define EXPRSHIFTLEFT_H
#include "binaryexpr.h"
class exprShiftLeft:public binaryExpr
{
public:
    exprShiftLeft();
    exprShiftLeft(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRSHIFTLEFT_H
