#ifndef STATEMENTRETURN_H
#define STATEMENTRETURN_H

#include "statement.h"
#include "expression.h"

class statementReturn: public statement
{
public:
    statementReturn(Expression* returnValue, int linea);
    void print();

private:
    Expression* returnValue;
};

#endif // STATEMENTRETURN_H
