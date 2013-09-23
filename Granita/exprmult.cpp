#include "exprmult.h"

exprMult::exprMult(Expression *left_expr, Expression *right_expr,int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprMult::print()
{
    this->left_expr->print();
    cout<<"*";
    this->rigth_expr->print();
}
newExpression * exprMult::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::INT && der->tipo == newExpression::INT)
            return new newExprMult(izq,der);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprMult::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}

