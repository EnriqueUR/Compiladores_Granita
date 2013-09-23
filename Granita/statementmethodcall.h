#ifndef STATEMENTMETHODCALL_H
#define STATEMENTMETHODCALL_H
#include <list>
#include <iostream>

#include "statement.h"
#include "expression.h"

using namespace std;
class statementMethodCall: public statement
{
public:
    statementMethodCall(string id, list<Expression*> *parameters, int linea);
    void print();

private:
    string id;
    list<Expression*> *parameters;
};

#endif // STATEMENTMETHODCALL_H
