#include "exprrot.h"

exprRot::exprRot()
{
}
exprRot::exprRot(Expression *left_expr, Expression *right_expr)
{
    this->left_expr = left_expr;
    this->rigth_expr = right_expr;
}
void exprRot::print()
{
    this->left_expr->print();
    cout<<"rot";
    this->rigth_expr->print();
}
