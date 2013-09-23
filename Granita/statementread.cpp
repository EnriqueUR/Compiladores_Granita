#include "statementread.h"

statementRead::statementRead(list<exprLvalue *> *lvalue, int linea)
{
    this->Linea = linea;
    this->lvalue = lvalue;
}
void statementRead::print()
{
    cout<<"read ";
    list<exprLvalue*>::iterator it;
    it = this->lvalue->begin();
    while(it != this->lvalue->end())
    {
        exprLvalue *lv = *it;
        lv->print();
        it++;
        if(it != this->lvalue->end())
            cout<<",";
    }

}


newStatement* statementRead::ValidarSemantica() {
    list<newExprLvalue*> *newArgs = new list<newExprLvalue*>();

    list<exprLvalue*>::iterator it;
    it = this->lvalue->begin();
    while(it != this->lvalue->end())
    {
        exprLvalue *lv = *it;
        newExprLvalue* lVal = (newExprLvalue*) lv->ValidarSermantica();
        if (lVal == NULL) {
            return NULL;
        }
        newArgs->push_back(lVal);
        it++;
    }
    return new newStatementRead(newArgs);
}
