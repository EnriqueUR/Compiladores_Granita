#ifndef NEWEXPRGREATERANDEQUAL_H
#define NEWEXPRGREATERANDEQUAL_H
#include "newbinaryexpr.h"

class newExprGreaterAndEqual : public newBinaryExpr
{
public:
    newExprGreaterAndEqual(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRGREATERANDEQUAL_H
