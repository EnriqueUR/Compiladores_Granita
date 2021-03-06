#include "exprlessthan.h"

exprLessThan::exprLessThan(Expression *left_expr, Expression *right_expr,int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprLessThan::print()
{
    this->left_expr->print();
    cout<<"<";
    this->rigth_expr->print();
}
newExpression * exprLessThan::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::BOOL && der->tipo == newExpression::BOOL)
            return new newExprLessThan(izq,der);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprLessThan::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
