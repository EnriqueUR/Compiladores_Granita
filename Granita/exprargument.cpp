#include "exprargument.h"

exprArgument::exprArgument(Expression *expr)
{
    this->expr = expr;
}
exprArgument::exprArgument(string stringConstant)
{
    this->stringConstant = stringConstant;
    this->expr = NULL;
}
void exprArgument::print()
{
    if(this->expr != NULL)
        this->expr->print();
    else
        cout<<this->stringConstant;
}
