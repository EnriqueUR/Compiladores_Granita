#ifndef EXPRBOOLCONSTANT_H
#define EXPRBOOLCONSTANT_H
#include "exprconstant.h"

class exprBoolConstant:public exprConstant
{
public:
    exprBoolConstant(bool boolConstant);
    void print();
private:
    bool boolConstant;
};

#endif // EXPRBOOLCONSTANT_H
