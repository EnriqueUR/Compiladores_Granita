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
    return new newStatementBreak();
}
