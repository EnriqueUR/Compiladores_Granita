#ifndef EXPRCONSTANT_H
#define EXPRCONSTANT_H
#include "expression.h"

class exprConstant:public Expression
{
public:
    exprConstant();
    void print();
};

#endif // EXPRCONSTANT_H
