#include "statementprint.h"

statementPrint::statementPrint(list<exprArgument *> *arguments, int linea)
{
    this->Linea = linea;
    this->arguments = arguments;
}

void statementPrint::print()
{
    cout<<"print ";
    list<exprArgument*>::iterator it;
    it = arguments->begin();
    while(it != this->arguments->end())
    {
        exprArgument *ar = *it;
        ar->print();
        it++;
    }
}
