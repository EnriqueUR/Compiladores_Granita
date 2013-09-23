#ifndef NEWEXPRDISTIN_H
#define NEWEXPRDISTIN_H
#include "newbinaryexpr.h"
class newExprDistin : public newBinaryExpr
{
public:
    newExprDistin(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRDISTIN_H
