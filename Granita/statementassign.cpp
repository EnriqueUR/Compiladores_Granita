#include "statementassign.h"

statementAssign::statementAssign(exprLvalue *lvalue, Expression *expr, int linea)
{
    this->Linea = linea;
    this->lvalue = lvalue;
    this->expr = expr;
}
void statementAssign::print()
{
    this->lvalue->print();
    cout<<"=";
    this->expr->print();
}
