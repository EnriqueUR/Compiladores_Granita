#ifndef STATEMENTMETHODECL_H
#define STATEMENTMETHODECL_H
#include <list>
#include "statementdeclaration.h"
#include "procedimiento.h"
#include "statementblock.h"

#include "newstatementblock.h"

#include "singletontable.h"
#include "tablasimboloslocal.h"
#include "analisissemantico.h"

using namespace std;
class statementMethodecl:public statementDeclaration
{
public:
    statementMethodecl(Type method_type,string method_name,
                       list<Type> *parameter_list_type,list<string> *parameter_list,
                       statementBlock *block, int linea);
    newStatement * ValidarSemantica();
    void print();
    string method_name;
private:
    Type method_type;

    list<Type> *parameter_list_type;
    list<string> *parameter_list;
    statementBlock *block;
};

#endif // STATEMENTMETHODECL_H
