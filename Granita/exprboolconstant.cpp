#include "exprboolconstant.h"

exprBoolConstant::exprBoolConstant(bool boolConstant)
{
    this->boolConstant = boolConstant;
}
void exprBoolConstant::print()
{
    if(this->boolConstant)
    {
        cout<<"bool";
    }
    else
    {
        cout<<"false";
    }
}
