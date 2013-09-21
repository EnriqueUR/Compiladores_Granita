#include "exprdistin.h"

exprDistin::exprDistin()
{
}
exprDistin::exprDistin(Expression *left_expr, Expression *right_expr)
{
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprDistin::print()
{
    this->left_expr->print();
    cout<<"!=";
    this->rigth_expr->print();
}
