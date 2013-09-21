#include "statementfor.h"

statementFor::statementFor(list<statementAssign *> *initialValues,
                           Expression *expr,
                           list<statementAssign *> *incrementValues,
                           statementBlock *block)
{
    this->initialValues = initialValues;
    this->expr = expr;
    this->incrementValues = incrementValues;
    this->block = block;
}
void statementFor::print()
{
    cout<<"for(";
    list<statementAssign*>::iterator it1;
    it1 = this->initialValues->begin();
    while(it1 != this->initialValues->end())
    {
        statementAssign *st = *it1;
        st->print();
        it1++;
        if(it1 != this->initialValues->end())
            cout<<",";
    }
    cout<<";";
    this->expr->print();
    cout<<";";
    list<statementAssign*>::iterator it2;
    it2 = this->incrementValues->begin();
    while(it2 != this->incrementValues->end())
    {
        statementAssign *st = *it2;
        st->print();
        it2++;
        if(it2 != this->incrementValues->end())
            cout<<",";
    }

    cout<<")"<<endl;
    this->block->print();

}
