#include "statementcontinue.h"

statementContinue::statementContinue(int linea)
{
    this->Linea = linea;
}
void statementContinue::print()
{
    cout<<"continue";
}


newStatement* statementContinue::ValidarSemantica() {
    return new newStatementContinue();
}
