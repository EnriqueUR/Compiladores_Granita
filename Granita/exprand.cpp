#include "exprand.h"

exprAnd::exprAnd(Expression *left_expr, Expression *right_expr, int linea)
{
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
    this->Linea = linea;
}
void exprAnd::print()
{
    this->left_expr->print();
    cout<<"&&";
    this->rigth_expr->print();
}
newExpression * exprAnd::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::BOOL && der->tipo == newExpression::BOOL)
            return new newExprAnd(izq,der);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprAnd::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
