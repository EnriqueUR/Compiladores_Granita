#ifndef EXPRCHARCONSTANT_H
#define EXPRCHARCONSTANT_H
#include "exprconstant.h"
class exprCharConstant:public exprConstant
{
public:
    exprCharConstant();
    exprCharConstant(char CharConstant);
    void print();
private:
    char charConstant;
};

#endif // EXPRCHARCONSTANT_H
