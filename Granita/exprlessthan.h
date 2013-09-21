#ifndef EXPRLESSTHAN_H
#define EXPRLESSTHAN_H
#include "binaryexpr.h"
class exprLessThan:public binaryExpr
{
public:
    exprLessThan();
    exprLessThan(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRLESSTHAN_H
