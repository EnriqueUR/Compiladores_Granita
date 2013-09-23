#ifndef BINARYEXPR_H
#define BINARYEXPR_H
#include "expression.h"
#include <iostream>

using namespace std;
class binaryExpr:public Expression
{
public:
    binaryExpr();
protected:
    Expression *left_expr;
    Expression *rigth_expr;

};

#endif // BINARYEXPR_H
