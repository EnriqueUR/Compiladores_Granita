#ifndef NEWEXPRLVALUE_H
#define NEWEXPRLVALUE_H
#include "newexpression.h"
#include "newexprlvalue.h"
class newExprLvalue : public newExpression
{
public:
    newExprLvalue(string id);
    newExprLvalue(string id,newExpression *expr);
    string id;
    newExpression *expr;
};

#endif // NEWEXPRLVALUE_H
