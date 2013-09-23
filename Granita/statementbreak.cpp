#include "statementbreak.h"

statementBreak::statementBreak(int linea)
{
    this->Linea = linea;
}
void statementBreak::print()
{
    cout<<"break";
}

newStatement* statementBreak::ValidarSemantica(){
    if (!AnalisisSemantico::dentroCiclo) {
        PrintError("break debe estar dentro de un ciclo");
        return NULL;
    }
    return new newStatementBreak();
}
