#ifndef STATEMENTMETHODECL_H
#define STATEMENTMETHODECL_H
#include <list>
#include "statementdeclaration.h"
#include "statementblock.h"

using namespace std;
class statementMethodecl:public statementDeclaration
{
public:
    statementMethodecl();
    statementMethodecl(Type method_type,string method_name,
                       list<Type> *parameter_list_type,list<string> *parameter_list,
                       statementBlock *block);
    void print();

private:
    Type method_type;
    string method_name;
    list<Type> *parameter_list_type;
    list<string> *parameter_list;
    statementBlock *block;
};

#endif // STATEMENTMETHODECL_H
