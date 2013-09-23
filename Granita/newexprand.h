#ifndef NEWEXPRAND_H
#define NEWEXPRAND_H
#include "newexpression.h"
#include "newbinaryexpr.h"
class newExprAnd : public newBinaryExpr
{
public:
    newExprAnd(newExpression* izq,newExpression* der);
};

#endif // NEWEXPRAND_H
