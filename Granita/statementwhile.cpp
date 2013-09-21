#include "statementwhile.h"

statementWhile::statementWhile(Expression *expr, statementBlock *block_true)
{
    this->block_true = block_true;
    this->expr = expr;
}
void statementWhile::print()
{
    cout<<"while(";
    expr->print();
    block_true->print();
}
