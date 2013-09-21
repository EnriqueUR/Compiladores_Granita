#ifndef EXPRGREATERTHAN_H
#define EXPRGREATERTHAN_H
#include "binaryexpr.h"
class exprGreaterThan:public binaryExpr
{
public:
    exprGreaterThan();
    exprGreaterThan(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRGREATERTHAN_H
