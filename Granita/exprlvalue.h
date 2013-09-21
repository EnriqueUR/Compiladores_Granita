#ifndef EXPRLVALUE_H
#define EXPRLVALUE_H
#include <iostream>
#include "expression.h"

using namespace std;
class exprLvalue: public Expression
{
public:
    exprLvalue();
    exprLvalue(string id);
    exprLvalue(string id,Expression *expr);
    string getId();
    void print();
    void setExpr(Expression *expr);
    void setId(string id);

//private:
    string id;
    Expression *expr;
};

#endif // EXPRLVALUE_H
