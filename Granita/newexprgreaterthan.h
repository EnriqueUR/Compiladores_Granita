#ifndef NEWEXPRGREATERTHAN_H
#define NEWEXPRGREATERTHAN_H
#include "newbinaryexpr.h"
class newExprGreaterThan : public newBinaryExpr
{
public:
    newExprGreaterThan(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRGREATERTHAN_H
