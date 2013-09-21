#include "statementreturn.h"

statementReturn::statementReturn(Expression *returnValue)
{
    this->returnValue = returnValue;
}
void statementReturn::print()
{
    cout<<"return ";
    if(this->returnValue!=NULL)
        this->returnValue->print();
}
