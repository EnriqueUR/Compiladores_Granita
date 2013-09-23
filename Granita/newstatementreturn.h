#ifndef NEWSTATEMENTRETURN_H
#define NEWSTATEMENTRETURN_H

#include "newstatement.h"
#include "newexpression.h"

class newStatementReturn: public newStatement
{
public:
    newStatementReturn(newExpression* retValue);

protected:
    newExpression* returnValue;
};

#endif // NEWSTATEMENTRETURN_H
