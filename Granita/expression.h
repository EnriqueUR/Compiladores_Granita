#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include "newexpression.h"

using namespace std;
class Expression
{
public:
    Expression();
    virtual void print()=0;
    virtual newExpression *ValidarSermantica()=0;
    virtual void PrintError(string msj)=0;
    int Linea;
};

#endif // EXPRESSION_H
