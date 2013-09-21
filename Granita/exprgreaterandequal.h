#ifndef EXPRGREATERANDEQUAL_H
#define EXPRGREATERANDEQUAL_H
#include "binaryexpr.h"
class exprGreaterAndEqual:public binaryExpr
{
public:
    exprGreaterAndEqual();
    exprGreaterAndEqual(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRGREATERANDEQUAL_H
