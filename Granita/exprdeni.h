#ifndef EXPRDENI_H
#define EXPRDENI_H
#include "unaryexpr.h"
class exprDeni:public unaryExpr
{
public:
    exprDeni();
    exprDeni(Expression *expr);
    void print();

};

#endif // EXPRDENI_H
