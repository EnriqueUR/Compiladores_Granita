#ifndef STATEMENTFIELDECL_H
#define STATEMENTFIELDECL_H
#include <iostream>
#include <list>
#include "statementdeclaration.h"
#include "exprintconstant.h"
#include "exprconstant.h"

using namespace std;
class statementFieldecl:public statementDeclaration
{
public:
    statementFieldecl();
    statementFieldecl(Type tipo,list<string> *list_only_id, list<string> *list_id,list<exprIntConstant*> *intConstant);
    statementFieldecl(Type tipo,string id,Expression *constant);
    void print();
private:
    string id;
    Type tipo;

    list<string> *list_only_id;
    list<string> *list_id;
    list<exprIntConstant*> *list_intConstant;

    Expression *constant;

};

#endif // STATEMENTFIELDECL_H
