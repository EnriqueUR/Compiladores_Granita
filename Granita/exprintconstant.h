#ifndef EXPRINTCONSTANT_H
#define EXPRINTCONSTANT_H
#include "exprconstant.h"
class exprIntConstant:public exprConstant
{
public:
    exprIntConstant(int intConstant, int linea);
    newExpression * ValidarSermantica();
    void print();
    void PrintError(string msj);

private:
    int intConstant;
};

#endif // EXPRINTCONSTANT_H
