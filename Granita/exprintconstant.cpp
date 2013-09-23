#include "exprintconstant.h"

exprIntConstant::exprIntConstant(int intConstant,int linea)
{
    this->Linea = linea;
    this->intConstant = intConstant;
}
void exprIntConstant::print()
{
    cout<<this->intConstant;
}
newExpression * exprIntConstant::ValidarSermantica()
{
    newExpression *expr = new newExpression();
    expr->tipo = newExpression::INT;
    return expr;
}
void exprIntConstant::PrintError(string msj)
{

}
