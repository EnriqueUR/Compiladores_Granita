#ifndef EXPRARGUMENT_H
#define EXPRARGUMENT_H
#include <iostream>
#include "expression.h"
#include "newexpression.h"
#include "newexprargument.h"

using namespace std;
class exprArgument:public Expression
{
public:
    exprArgument(Expression *expr, int linea);
    exprArgument(string stringConstant,int linea);
    newExpression * ValidarSermantica();

    void print();
    void PrintError(string msj);
private:
    Expression *expr;
    string stringConstant;

};

#endif // EXPRARGUMENT_H
