#ifndef NEWEXPRMULT_H
#define NEWEXPRMULT_H
#include "newbinaryexpr.h"
class newExprMult : public  newBinaryExpr
{
public:
    newExprMult(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRMULT_H
