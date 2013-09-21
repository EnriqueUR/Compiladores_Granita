#ifndef EXPRLESSANDEQUAL_H
#define EXPRLESSANDEQUAL_H
#include "binaryexpr.h"
class exprLessAndEqual:public binaryExpr
{
public:
    exprLessAndEqual();
    exprLessAndEqual(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRLESSANDEQUAL_H
