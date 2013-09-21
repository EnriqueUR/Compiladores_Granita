#include "exprintconstant.h"

exprIntConstant::exprIntConstant(int intConstant)
{
    this->intConstant = intConstant;
}
void exprIntConstant::print()
{
    cout<<this->intConstant;
}
