#ifndef NEWEXPRMETHODCALL_H
#define NEWEXPRMETHODCALL_H
#include "newexpression.h"
#include <list>

class newExprMethodCall:public newExpression
{
public:
    newExprMethodCall(string id,list<newExpression*> *newExprList);

    list<newExpression*> *newExprList;
    string id;

};

#endif // NEWEXPRMETHODCALL_H
