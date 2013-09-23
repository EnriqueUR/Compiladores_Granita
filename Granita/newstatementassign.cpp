#include "newstatementassign.h"

newStatementAssign::newStatementAssign(newExpression *lvalue, newExpression *value)
{
    this->lvalue = lvalue;
    this->value = value;
}
