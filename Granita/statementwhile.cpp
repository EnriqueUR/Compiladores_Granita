#include "statementwhile.h"

statementWhile::statementWhile(Expression *expr, statementBlock *block_true, int linea)
{
    this->Linea = linea;
    this->block_true = block_true;
    this->expr = expr;
}
void statementWhile::print()
{
    cout<<"while(";
    expr->print();
    cout<<")";
    block_true->print();
}
