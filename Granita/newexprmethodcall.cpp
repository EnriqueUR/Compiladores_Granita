#include "newexprmethodcall.h"

newExprMethodCall::newExprMethodCall(string id, list<newExpression *> *newExprList)
{
    this->id = id;
    this->newExprList = newExprList;
}
