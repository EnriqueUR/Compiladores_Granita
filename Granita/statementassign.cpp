#include "statementassign.h"

statementAssign::statementAssign(exprLvalue *lvalue, Expression *expr)
{
    this->lvalue = lvalue;
    this->expr = expr;
}
void statementAssign::print()
{
    this->lvalue->print();
    cout<<"=";
    this->expr->print();
}
