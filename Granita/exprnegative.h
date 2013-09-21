#ifndef EXPRNEGATIVE_H
#define EXPRNEGATIVE_H
#include "unaryexpr.h"
class exprNegative:public unaryExpr
{
public:
    exprNegative();
    exprNegative(Expression *expr);
    void print();
};

#endif // EXPRNEGATIVE_H
