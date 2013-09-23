#ifndef NEWSTATEMENTASSIGN_H
#define NEWSTATEMENTASSIGN_H

#include "newexprlvalue.h"
#include "newexpr.h"
#include "newstatement.h"

class newStatementAssign: public newStatement
{
public:
    newStatementAssign(newExpression* lvalue, newExpression* value);

protected:
    newExpression* lvalue;
    newExpression* value;
};

#endif // NEWSTATEMENTASSIGN_H
