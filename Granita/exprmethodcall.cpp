#include "exprmethodcall.h"

exprMethodCall::exprMethodCall(string name, list<Expression*> *parameters,int linea)
{
    this->Linea = linea;
    this->name = name;
    this->parameters = parameters;
}
void exprMethodCall::print()
{
    cout<<this->name<<"(";
    list<Expression*>::iterator pos;
    pos = parameters->begin();
    while( pos != parameters->end())
    {
        Expression *e = *pos;
        e->print();
        pos++;
        if(pos != parameters->end())
            cout<<",";
    }
}
newExpression *exprMethodCall::ValidarSermantica()
{
    list<newExpression*>* newExprList = new list<newExpression*>();
    list<Expression*>::iterator it;
    it = this->parameters->begin();
    while(it != this->parameters->end())
    {
        Expression * expr = *it;
        newExprList->push_back(expr->ValidarSermantica());
    }
    return new newExprMethodCall(this->name,newExprList);

}
void exprMethodCall::PrintError(string msj)
{
    cout<<"linea:"<< this->Linea<<" ERROR Semantico: "<<endl;
    cout<<msj;
}

