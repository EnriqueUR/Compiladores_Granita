#include "statementfor.h"

statementFor::statementFor(list<statementAssign *> *initialValues,
                           Expression *expr,
                           list<statementAssign *> *incrementValues,
                           statementBlock *block,int linea)
{
    this->Linea = linea;
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

newStatement* statementFor::ValidarSemantica() {
    list<newStatementAssign*> *inits = new list<newStatement*>();
    list<statementAssign*>::iterator it1;
    it1 = this->initialValues->begin();
    while(it1 != this->initialValues->end())
    {
        statementAssign *st = *it1;
        newStatementAssign* assi = (newStatementAssign*) st->ValidarSemantica();
        if (assi == NULL) {
            return NULL;
        }
        inits->push_back(assi);
        it1++;
    }

    list<newStatementAssign*> *incrs = new list<newStatement*>();
    list<statementAssign*>::iterator it2;
    it2 = this->incrementValues->begin();
    while(it2 != this->incrementValues->end())
    {
        statementAssign *st = *it2;
        newStatementAssign* assi = (newStatementAssign*) st->ValidarSemantica();
        if (assi == NULL) {
            return NULL;
        }
        incrs->push_back(assi);
        it2++;
    }

    newExpression* cond = expr->ValidarSermantica();
    if (cond == NULL) {
        return NULL;
    }
    if (cond->tipo != BOOL) {
        PrintError("Condicion del For debe ser booleana");
        return NULL;
    }

    newStatementBlock* newBlock = (newStatementBlock*) this->block->ValidarSemantica();
    if (newBlock == NULL) {
        return NULL;
    }

    return new newStatementFor(inits, expr, incrs, newBlock);
}
