#include "newexprlvalue.h"

newExprLvalue::newExprLvalue(string id)
{
    this->id = id;
    this->expr = NULL;
}
newExprLvalue::newExprLvalue(string id,newExpression * expr)
{
    this->id = id;
    this->expr = expr;
}
