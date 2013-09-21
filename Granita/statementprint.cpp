#include "statementprint.h"

statementPrint::statementPrint(list<exprArgument *> *arguments)
{
    this->arguments = arguments;
}

void statementPrint::print()
{
    list<exprArgument*>::iterator it;
    it = arguments->begin();
    while(it != this->arguments->end())
    {
        exprArgument *ar = *it;
        ar->print();
        it++;
    }
}
