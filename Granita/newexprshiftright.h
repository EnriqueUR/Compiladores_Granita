#ifndef NEWEXPRSHIFTRIGHT_H
#define NEWEXPRSHIFTRIGHT_H
#include "newbinaryexpr.h"
class newExprShiftRight : public newBinaryExpr
{
public:
    newExprShiftRight(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRSHIFTRIGHT_H
