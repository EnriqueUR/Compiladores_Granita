#ifndef EXPRID_H
#define EXPRID_H
#include <iostream>
#include "expression.h"

using namespace std;
class exprId:public Expression
{
public:
    exprId();
    exprId(string Id);
    void print();
private:
    string Id;
};

#endif // EXPRID_H
