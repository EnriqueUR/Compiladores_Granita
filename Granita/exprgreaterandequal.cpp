#include "exprgreaterandequal.h"

exprGreaterAndEqual::exprGreaterAndEqual(Expression *left_expr, Expression *right_expr,int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprGreaterAndEqual::print()
{
    this->left_expr->print();
    cout<<">=";
    this->rigth_expr->print();
}
newExpression * exprGreaterAndEqual::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::INT && der->tipo == newExpression::INT)
            return new newExprGreaterAndEqual(izq,der);
        PrintError("Tipos Incompatibles");
    }

}
void exprGreaterAndEqual::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
