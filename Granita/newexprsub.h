#ifndef NEWEXPRSUB_H
#define NEWEXPRSUB_H
#include "newbinaryexpr.h"
class newExprSub : public newBinaryExpr
{
public:
    newExprSub(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRSUB_H
