#ifndef EXPRMULT_H
#define EXPRMULT_H
#include "binaryexpr.h"
class exprMult:public binaryExpr
{
public:
    exprMult();
    exprMult(Expression *left_expr,Expression *right_expr);
    void print();
};

#endif // EXPRMULT_H
