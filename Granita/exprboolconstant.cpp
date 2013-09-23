#include "exprboolconstant.h"

exprBoolConstant::exprBoolConstant(bool boolConstant,int linea)
{
    this->Linea = linea;
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
newExpression * exprBoolConstant::ValidarSermantica()
{
    newExpression *expr = new newExpression();
    expr->tipo = newExpression::BOOL;
    return expr;
}
void exprBoolConstant::PrintError(string msj)
{

}
