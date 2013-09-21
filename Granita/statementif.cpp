#include "statementif.h"

statementIf::statementIf(Expression *expr, statementBlock *block_true)
{
    this->expr = expr;
    this->block_true = block_true;
    this->block_false = NULL;
}

statementIf::statementIf(Expression *expr,
                         statementBlock *block_true,
                         statementBlock *block_false)
{
    this->expr = expr;
    this->block_true = block_true;
    this->block_false = block_false;
}
void statementIf::print()
{
    cout<<"if(";
    this->expr->print();
    cout<<")";
    this->block_true->print();

    if(this->block_false!= NULL)
        this->block_false->print();
}
