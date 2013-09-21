#ifndef EXPRINTCONSTANT_H
#define EXPRINTCONSTANT_H
#include "exprconstant.h"
class exprIntConstant:public exprConstant
{
public:
    exprIntConstant(int intConstant);
    void print();

private:
    int intConstant;
};

#endif // EXPRINTCONSTANT_H
