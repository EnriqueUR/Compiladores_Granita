#include "exprrot.h"

exprRot::exprRot(Expression *left_expr, Expression *right_expr,int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprRot::print()
{
    this->left_expr->print();
    cout<<"rot";
    this->rigth_expr->print();
}
newExpression * exprRot::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::INT && der->tipo == newExpression::INT)
            return new newExprRot(izq,der);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprRot::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
