#include "exprlvalue.h"
exprLvalue::exprLvalue()
{
    this->id = "";
    this->expr = NULL;
}
exprLvalue::exprLvalue(string id)
{
    this->id = id;
    this->expr = NULL;
}

exprLvalue::exprLvalue(string id, Expression *expr) {
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
