#include "statementwhile.h"

statementWhile::statementWhile(Expression *expr, statementBlock *block_true, int linea)
{
    this->Linea = linea;
    this->block_true = block_true;
    this->expr = expr;
}
void statementWhile::print()
{
    cout<<"while(";
    expr->print();
    cout<<")";
    block_true->print();
}


newStatement* statementWhile::ValidarSemantica() {
    newExpression* condicion = this->expr->ValidarSermantica();
    if (condicion == NULL) {
        return NULL;
    }
    if (condicion->tipo != BOOL) {
        PrintError("Condicion en el while debe ser booleana");
        return NULL;
    }

    newStatementBlock* newBlock = this->block_true->ValidarSemantica();
    if (newBlock == NULL) {
        return NULL;
    }

    return new newStatementWhile(condicion, newBlock);
}
