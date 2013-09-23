#ifndef NEWEXPRNEGATIVE_H
#define NEWEXPRNEGATIVE_H
#include "newunaryexpr.h"
class newExprNegative : public newUnaryExpr
{
public:
    newExprNegative(newExpression *expr);
};

#endif // NEWEXPRNEGATIVE_H
