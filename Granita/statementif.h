#ifndef STATEMENTIF_H
#define STATEMENTIF_H
#include "statement.h"
#include "expression.h"
#include "statementblock.h"

#include "newstatementblock.h"
#include "newstatementif.h"

class statementIf : public statement
{
public:
    statementIf(Expression *expr,statementBlock *block_true, int linea);
    statementIf(Expression *expr,statementBlock *block_true, statementBlock *block_false, int linea);
    void print();

private:
    Expression *expr;
    statementBlock *block_true;
    statementBlock *block_false;
};

#endif // STATEMENTIF_H
