#ifndef EXPREQUAL_H
#define EXPREQUAL_H
#include "binaryexpr.h"
class exprEqual:public binaryExpr
{
public:
    exprEqual();
    exprEqual(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPREQUAL_H
