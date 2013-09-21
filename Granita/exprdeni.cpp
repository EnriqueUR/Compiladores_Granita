#include "exprdeni.h"

exprDeni::exprDeni()
{
}
exprDeni::exprDeni(Expression *expr)
{
    this->expr = expr;
}
void exprDeni::print()
{
    cout<<"!";
    this->expr->print();
}
