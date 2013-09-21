#ifndef EXPROR_H
#define EXPROR_H
#include "binaryexpr.h"
class ExprOr:public binaryExpr
{
public:
    ExprOr(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPROR_H
