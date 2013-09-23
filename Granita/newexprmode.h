#ifndef NEWEXPRMODE_H
#define NEWEXPRMODE_H
#include "newbinaryexpr.h"
class newExprMode : public newBinaryExpr
{
public:
    newExprMode(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRMODE_H
