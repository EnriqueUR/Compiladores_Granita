#ifndef STATEMENTASSIGN_H
#define STATEMENTASSIGN_H
#include "exprlvalue.h"
#include "expression.h"
#include "statement.h"

#include "newstatementassign.h"

class statementAssign:public statement
{
public:
    statementAssign(exprLvalue *lvalue,Expression *expr, int linea);
    newStatement * ValidarSemantica();
    void print();

protected:
    exprLvalue *lvalue;
    Expression *expr;

};

#endif // STATEMENTASSIGN_H
