#include "var_decl.h"

var_decl::var_decl(list<string> *string_var) {
    this->string_var = string_var;
}

void var_decl::setType(Type type) {
    this->type = type;
}

void var_decl::print()
{
    if(this->type == BOOL)
    {
        cout<<"bool ";
    }
    else
    {
        cout<<"int ";
    }
    list<string>::iterator it;
    it = this->string_var->begin();
    while(it != this->string_var->end())
    {
        string s = *it;
        cout<<s;
        it++;
    }
}
