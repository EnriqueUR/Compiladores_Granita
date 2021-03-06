#ifndef STATEMENTWHILE_H
#define STATEMENTWHILE_H
#include "statement.h"
#include "expression.h"
#include "statementblock.h"

#include "newstatement.h"
#include "newexpression.h"
#include "newstatementblock.h"
#include "newstatementwhile.h"
#include "analisissemantico.h"

class statementWhile:public statement
{
public:
    statementWhile(Expression *expr,statementBlock *block_true, int linea);
    newStatement * ValidarSemantica();
    void print();

private:
    Expression *expr;
    statementBlock *block_true;
};

#endif // STATEMENTWHILE_H
