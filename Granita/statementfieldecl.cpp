#include "statementfieldecl.h"

statementFieldecl::statementFieldecl(Type tipo, string id, Expression *constant, int linea)
{
    this->Linea = linea;
    this->tipo = tipo;
    this->id = id;
    this->constant = constant;
}
statementFieldecl::statementFieldecl(Type tipo, list<string> *list_only_id,
                                     list<string> *list_id, list<exprIntConstant*> *intConstant,int linea)
{
    this->Linea = linea;
    this->tipo = tipo;
    this->list_only_id = list_only_id;
    this->list_id = list_id;
    this->list_intConstant = intConstant;

    this->constant = NULL;
}
void statementFieldecl::print()
{
    if(this->tipo == statementDeclaration::BOOL)
        cout<<"bool ";
    else
        cout<<"int ";

    if(this->constant != NULL)
    {
        cout<<this->id<<"=";
        this->constant->print();
    }
    else
    {
        list<string>::iterator it1;
        it1 = this->list_only_id->begin();
        while(it1 != this->list_only_id->end())
        {
            cout<<*it1;
            it1++;
        }
        if(this->list_id != NULL && this->list_intConstant!= NULL){
            list<string>::iterator it2;
            it2 = this->list_id->begin();

            list<exprIntConstant *>::iterator it3;
            it3 = this->list_intConstant->begin();
            while((it1 != this->list_only_id->end())||(it3 != this->list_intConstant->end()))
            {
                exprIntConstant* intconst = *it3;
                cout<<*it2<<"[";
                intconst->print();
                cout<<"]";
                it2++;
                it3++;
            }
        }

    }
}
