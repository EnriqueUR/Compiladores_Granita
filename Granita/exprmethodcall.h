#ifndef EXPRMETHODCALL_H
#define EXPRMETHODCALL_H
#include "expression.h"
#include <iostream>
#include <list>
#include "newexpression.h"
#include "newexprmethodcall.h"

using namespace std;
class exprMethodCall:public Expression
{
public:
    exprMethodCall(string name, list<Expression*> *parameters, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);

private:
    string name;
    list<Expression*> *parameters;

};

#endif // EXPRMETHODCALL_H
