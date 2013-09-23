#ifndef NEWEXPRARGUMENT_H
#define NEWEXPRARGUMENT_H
#include "newexpression.h"

class newExprArgument : public newExpression
{
public:
    newExprArgument(newExpression *expr);
    newExprArgument(string stringConstant);
};

#endif // NEWEXPRARGUMENT_H
