#include "statementmethodcall.h"

statementMethodCall::statementMethodCall(string id, list<Expression *> *parameters,int linea)
{
    this->Linea = linea;
    this->id = id;
    this->parameters = parameters;
}
void statementMethodCall::print()
{
    cout<<this->id<<"(";
    list<Expression*>::iterator it;
    it = parameters->begin();
    while(it != parameters->end())
    {
        Expression *ex = *it;
        ex->print();
        it++;
        if(it != parameters->end())
            cout<<",";
    }
    cout<<")"<<endl;
}
