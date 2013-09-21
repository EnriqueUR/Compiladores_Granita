#ifndef EXPRMETHODCALL_H
#define EXPRMETHODCALL_H
#include "expression.h"
#include <iostream>
#include <list>

using namespace std;
class exprMethodCall:public Expression
{
public:
    exprMethodCall(string name, list<Expression*> *parameters);
    void print();

private:
    string name;
    list<Expression*> *parameters;

};

#endif // EXPRMETHODCALL_H
