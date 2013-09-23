#ifndef UNARYEXPR_H
#define UNARYEXPR_H
#include "expression.h"

class unaryExpr:public Expression
{
public:
    unaryExpr();

protected:
    void print();
    Expression *expr;


};

#endif // UNARYEXPR_H
