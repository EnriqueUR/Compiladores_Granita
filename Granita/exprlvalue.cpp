#include "exprlvalue.h"
exprLvalue::exprLvalue(int linea)
{
    this->id = "";
    this->expr = NULL;
}
exprLvalue::exprLvalue(string id,int linea)
{
    this->Linea = linea;
    this->id = id;
    this->expr = NULL;
}

exprLvalue::exprLvalue(string id, Expression *expr,int linea)
{
    this->Linea = linea;
    this->id = id;
    this->expr = expr;
}
string exprLvalue::getId()
{
    return this->id;
}
void exprLvalue::setExpr(Expression *expr)
{
    this->expr = expr;
}
void exprLvalue::setId(string id)
{
    this->id = id;
}
void exprLvalue::print()
{
    if(this->expr != NULL){
        cout<<this->id;
        cout<<"[";
        this->expr->print();
        cout<<"]";
    }else
        cout<<this->id;
}
newExpression * exprLvalue::ValidarSermantica()
{
    if(this->expr!= NULL)
    {
        newExpression *newexpr = this->expr->ValidarSermantica();
        return new newExprLvalue(this->id,newexpr);
    }
    else
    {
        return new newExprLvalue(this->id);
    }

}
void exprLvalue::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}
