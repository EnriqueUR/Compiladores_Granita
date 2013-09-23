#include "newstatementassign.h"

newStatementAssign::newStatementAssign(newExprLvalue *lvalue, newExpr *value)
{
    this->lvalue = lvalue;
    this->value = value;
}
