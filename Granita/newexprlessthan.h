#ifndef NEWEXPRLESSTHAN_H
#define NEWEXPRLESSTHAN_H
#include "newbinaryexpr.h"
class newExprLessThan : public newBinaryExpr
{
public:
    newExprLessThan(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRLESSTHAN_H
