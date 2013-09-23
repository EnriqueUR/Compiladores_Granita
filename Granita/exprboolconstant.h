#ifndef EXPRBOOLCONSTANT_H
#define EXPRBOOLCONSTANT_H
#include "exprconstant.h"
#include "newexpression.h"

class exprBoolConstant:public exprConstant
{
public:
    exprBoolConstant(bool boolConstant, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);
private:
    bool boolConstant;
};

#endif // EXPRBOOLCONSTANT_H
