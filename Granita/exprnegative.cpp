#include "exprnegative.h"

exprNegative::exprNegative(Expression *expr,int linea)
{
    this->Linea = linea;
    this->expr = expr;
}
void exprNegative::print()
{
    cout<<"-";
    this->expr->print();
}
newExpression * exprNegative::ValidarSermantica()
{
    newExpression * expr = this->expr->ValidarSermantica();
    if(expr != NULL)
    {
        if(expr->tipo == newExpression::INT)
            return new newExprNegative(expr);
        PrintError("Tipos Incompatibles");
    }
}
void exprNegative::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}

