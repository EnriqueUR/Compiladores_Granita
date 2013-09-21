#ifndef EXPRARGUMENT_H
#define EXPRARGUMENT_H
#include <iostream>
#include "expression.h"

using namespace std;
class exprArgument:public Expression
{
public:
    exprArgument(Expression *expr);
    exprArgument(string stringConstant);
    void print();
private:
    Expression *expr;
    string stringConstant;

};

#endif // EXPRARGUMENT_H
