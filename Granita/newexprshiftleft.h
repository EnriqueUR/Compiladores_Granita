#ifndef NEWEXPRSHIFTLEFT_H
#define NEWEXPRSHIFTLEFT_H
#include "newbinaryexpr.h"
class newExprShiftLeft : public newBinaryExpr
{
public:
    newExprShiftLeft(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRSHIFTLEFT_H
