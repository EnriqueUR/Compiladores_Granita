#ifndef NEWEXPRLESSANDEQUAL_H
#define NEWEXPRLESSANDEQUAL_H
#include "newbinaryexpr.h"
class newExprLessAndEqual : public newBinaryExpr
{
public:
    newExprLessAndEqual(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRLESSANDEQUAL_H
