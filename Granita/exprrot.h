#ifndef EXPRROT_H
#define EXPRROT_H
#include "binaryexpr.h"
class exprRot:public binaryExpr
{
public:
    exprRot();
    exprRot(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRROT_H
