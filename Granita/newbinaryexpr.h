#ifndef NEWBINARYEXPR_H
#define NEWBINARYEXPR_H
#include "newexpression.h"
class newBinaryExpr : public newExpression
{
public:
    newBinaryExpr();
    newExpression *izq;
    newExpression *der;
};

#endif // NEWBINARYEXPR_H
