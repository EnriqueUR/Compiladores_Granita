#ifndef EXPRADD_H
#define EXPRADD_H
#include "binaryexpr.h"

class exprAdd:public binaryExpr
{
public:
    exprAdd(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRADD_H
