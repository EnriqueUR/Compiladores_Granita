#include "exprmethodcall.h"

exprMethodCall::exprMethodCall(string name, list<Expression*> *parameters)
{
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
