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

newStatement* statementPrint::ValidarSemantica() {
    list<newExprArgument*> *newArgs = new list<newExprArgument*>();

    list<exprArgument*>::iterator it;
    it = arguments->begin();
    while(it != this->arguments->end())
    {
        exprArgument *ar = *it;
        newExprArgument* arg = (newExprArgument*)ar->ValidarSermantica();
        if (arg == NULL) {
            return NULL;
        }
        newArgs->push_back(arg);
        it++;
    }
    return new newStatementPrint(newArgs);
}
