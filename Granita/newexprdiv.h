#ifndef NEWEXPRDIV_H
#define NEWEXPRDIV_H
#include "newbinaryexpr.h"

class newExprDiv : public newBinaryExpr
{
public:
    newExprDiv(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRDIV_H
