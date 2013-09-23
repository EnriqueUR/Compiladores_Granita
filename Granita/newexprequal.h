#ifndef NEWEXPREQUAL_H
#define NEWEXPREQUAL_H
#include "newbinaryexpr.h"

class newExprEqual : public newBinaryExpr
{
public:
    newExprEqual(newExpression *izq,newExpression *der);
};

#endif // NEWEXPREQUAL_H
