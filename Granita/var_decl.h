#ifndef VAR_DECL_H
#define VAR_DECL_H
#include <iostream>
#include <list>

#include "statementdeclaration.h"

using namespace std;
class var_decl : public statementDeclaration
{
public:
    var_decl(list<string> *string_var, int linea);
    void setType(Type type);
    void print();
private:
    list<string> *string_var;
    Type type;
};

#endif // VAR_DECL_H
