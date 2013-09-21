#include "exprid.h"

exprId::exprId()
{
}
exprId::exprId(string Id)
{
    this->Id = Id;
}
void exprId::print()
{
    cout<<this->Id;
}
