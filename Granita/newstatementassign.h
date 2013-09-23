#ifndef NEWSTATEMENTASSIGN_H
#define NEWSTATEMENTASSIGN_H

#include "newexprlvalue.h"
#include "newexpr.h"
#include "newstatement.h"

class newStatementAssign: public newStatement
{
public:
    newStatementAssign(newExprLvalue* lvalue, newExpr* value);

protected:
    newExprLvalue* lvalue;
    newExpr* value;
};

#endif // NEWSTATEMENTASSIGN_H
