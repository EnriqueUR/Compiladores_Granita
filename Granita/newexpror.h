#ifndef NEWEXPROR_H
#define NEWEXPROR_H
#include "newbinaryexpr.h"
class newExprOr : public newBinaryExpr
{
public:
    newExprOr(newExpression *izq,newExpression *der);
};

#endif // NEWEXPROR_H
