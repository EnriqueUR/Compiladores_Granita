#ifndef STATEMENTFIELDECL_H
#define STATEMENTFIELDECL_H
#include <iostream>
#include <list>
#include "statementdeclaration.h"
#include "exprintconstant.h"
#include "exprconstant.h"

#include "singletontable.h"
#include "variablesimple.h"
#include "variablearreglo.h"

using namespace std;
class statementFieldecl:public statementDeclaration
{
public:
    statementFieldecl(Type tipo,list<string> *list_only_id, list<string> *list_id,list<exprIntConstant*> *intConstant, int linea);
    statementFieldecl(Type tipo,string id,Expression *constant,int linea);
    void print();
    void PrintError(string msj);
    newStatement* ValidarSemantica();
private:
    string id;
    Type tipo;

    list<string> *list_only_id;
    list<string> *list_id;
    list<exprIntConstant*> *list_intConstant;

    Expression *constant;

};

#endif // STATEMENTFIELDECL_H
