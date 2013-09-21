#include "exprnegative.h"

exprNegative::exprNegative()
{
}
exprNegative::exprNegative(Expression *expr)
{
    this->expr = expr;
}
void exprNegative::print()
{
    cout<<"-";
    this->expr->print();
}
