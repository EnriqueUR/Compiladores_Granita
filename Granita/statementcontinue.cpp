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
    if (!AnalisisSemantico::dentroCiclo) {
        PrintError("continue debe estar dentro de un ciclo");
        return NULL;
    }
    return new newStatementContinue();
}
