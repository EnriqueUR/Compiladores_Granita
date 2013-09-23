#ifndef NEWEXPRROT_H
#define NEWEXPRROT_H
#include "newbinaryexpr.h"
class newExprRot : public newBinaryExpr
{
public:
    newExprRot(newExpression *izq,newExpression *der);
};

#endif // NEWEXPRROT_H
