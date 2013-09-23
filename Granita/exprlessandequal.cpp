#include "exprlessandequal.h"

exprLessAndEqual::exprLessAndEqual(Expression *left_expr, Expression *right_expr,int linea)
{
    this->Linea = linea;
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprLessAndEqual::print()
{
    this->left_expr->print();
    cout<<"<=";
    this->rigth_expr->print();
}
newExpression * exprLessAndEqual::ValidarSermantica()
{
    newExpression * izq = this->left_expr->ValidarSermantica();
    newExpression * der = this->rigth_expr->ValidarSermantica();
    if(izq != NULL && der != NULL)
    {
        if(izq->tipo == newExpression::INT && der->tipo == newExpression::INT)
            return new newExprLessAndEqual(izq,der);
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return NULL;

}
void exprLessAndEqual::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}

