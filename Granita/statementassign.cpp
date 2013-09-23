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

newStatement* statementAssign::ValidarSemantica() {
    newExpression* newLvalue = lvalue->ValidarSermantica();
    newExpression* newExprValue = expr->ValidarSermantica();

    if (newLvalue == NULL || newExprValue == NULL) {
        return NULL;
    }
    if (newLvalue->tipo != newExprValue->tipo) {
        PrintError("Tipos Incompatibles");
        return NULL;
    }
    return new newStatementAssign(newLvalue, newExprValue);
}
