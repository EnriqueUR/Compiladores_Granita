#include "exprargument.h"

exprArgument::exprArgument(Expression *expr,int linea)
{
    this->Linea = linea;
    this->expr = expr;
}
exprArgument::exprArgument(string stringConstant,int linea)
{
    this->Linea = linea;
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
newExpression * exprArgument::ValidarSermantica()
{
    if(this->expr != NULL)
    {
        newExpression *newexpr;
        newexpr = this->expr->ValidarSermantica();
        return new newExprArgument(newexpr);
    }
    else
    {
        return new newExprArgument(this->stringConstant);
    }
}
void exprArgument::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
