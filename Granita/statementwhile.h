#ifndef STATEMENTWHILE_H
#define STATEMENTWHILE_H
#include "statement.h"
#include "expression.h"
#include "statementblock.h"
class statementWhile:public statement
{
public:
    statementWhile(Expression *expr,statementBlock *block_true, int linea);
    void print();
private:
    Expression *expr;
    statementBlock *block_true;
};

#endif // STATEMENTWHILE_H
