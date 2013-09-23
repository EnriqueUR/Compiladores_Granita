#ifndef NEWUNARYEXPR_H
#define NEWUNARYEXPR_H
#include "newexpression.h"
class newUnaryExpr : public newExpression
{
public:
    newUnaryExpr();
    newExpression *expr;
};

#endif // NEWUNARYEXPR_H
