#include "statementreturn.h"

statementReturn::statementReturn(Expression *returnValue, int linea)
{
    this->Linea = linea;
    this->returnValue = returnValue;
}
void statementReturn::print()
{
    cout<<"return ";
    if(this->returnValue!=NULL)
        this->returnValue->print();
}


newStatement* statementReturn::ValidarSemantica() {
    newExpression* retVal = this->returnValue->ValidarSermantica();

    return new newStatementReturn(retVal);
}
