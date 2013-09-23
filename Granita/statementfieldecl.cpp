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
    }else
    {

    }
}
