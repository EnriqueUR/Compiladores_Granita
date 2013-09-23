#include "exprsub.h"

exprSub::exprSub(Expression *left_expr, Expression *right_expr, int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprSub::print()
{
    this->left_expr->print();
    cout<<"-";
    this->rigth_expr->print();
}
newExpression * exprSub::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::INT && der->tipo == newExpression::INT)
            return new newExprSub(izq,der);
        PrintError("Tipos Incompatibles");
    }

}
void exprSub::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
