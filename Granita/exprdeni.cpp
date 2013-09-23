#include "exprdeni.h"

exprDeni::exprDeni()
{
}
exprDeni::exprDeni(Expression *expr,int linea)
{
    this->Linea = linea;
    this->expr = expr;
}
void exprDeni::print()
{
    cout<<"!";
    this->expr->print();
}
newExpression * exprDeni::ValidarSermantica()
{
    newExpression * expr = this->expr->ValidarSermantica();
    if(expr != NULL)
    {
        if(expr->tipo == newExpression::BOOL)
            return new newExprDeni(expr);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprDeni::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}

