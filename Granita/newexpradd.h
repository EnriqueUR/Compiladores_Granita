#ifndef NEWEXPRADD_H
#define NEWEXPRADD_H
#include "newexpression.h"
#include "newbinaryexpr.h"

class newExprAdd:public newBinaryExpr
{
public:
    newExprAdd(newExpression* izq,newExpression* der);
};

#endif // NEWEXPRADD_H
