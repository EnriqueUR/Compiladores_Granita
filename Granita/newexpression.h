#ifndef NEWEXPRESSION_H
#define NEWEXPRESSION_H
#include <iostream>
using namespace std;
class newExpression
{
public:
    enum Type {BOOL,INT};
    newExpression();
    Type tipo;
};

#endif // NEWEXPRESSION_H
