#include "statementif.h"

statementIf::statementIf(Expression *expr, statementBlock *block_true, int linea)
{
    this->Linea = linea;
    this->expr = expr;
    this->block_true = block_true;
    this->block_false = NULL;
}

statementIf::statementIf(Expression *expr,
                         statementBlock *block_true,
                         statementBlock *block_false,int linea)
{
    this->Linea = linea;
    this->expr = expr;
    this->block_true = block_true;
    this->block_false = block_false;
}
void statementIf::print()
{
    cout<<"if(";
    this->expr->print();
    cout<<")";
    this->block_true->print();

    if(this->block_false!= NULL)
        this->block_false->print();
}

newStatement* statementIf::ValidarSemantica() {
    newExpression* condicion = this->expr->ValidarSermantica();
    if (condicion == NULL) {
        return NULL;
    }
    if (condicion->tipo != BOOL) {
        PrintError("Condicion del if debe ser booleana");
        return NULL;
    }
    newStatementBlock* newTrueBlock = this->block_true->ValidarSemantica();
    newStatementBlock* newFalseBlock = this->block_false->ValidarSemantica();
    if (newTrueBlock == NULL) {
        return NULL;
    }
    if (this->block_false != NULL) {
        newFalseBlock = this->block_false->ValidarSemantica();
        if (newFalseBlock == NULL) {
            return NULL;
        }
    }
    return new newStatementIf(condicion, newTrueBlock, newFalseBlock);
}
