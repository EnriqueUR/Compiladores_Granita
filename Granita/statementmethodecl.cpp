#include "statementmethodecl.h"

statementMethodecl::statementMethodecl(Type method_type, string method_name,
                                       list<Type> *parameter_list_type,
                                       list<string> *parameter_list,
                                       statementBlock *block,int linea)
{
    this->Linea = linea;
    this->method_type = method_type;
    this->method_name = method_name;
    this->parameter_list_type = parameter_list_type;
    this->parameter_list = parameter_list;
    this->block = block;
}
void statementMethodecl::print()
{
    if(this->method_type == VOID)
    {
        cout<<"void ";
    }
    else if(this->method_type==INT)
    {
        cout<<"int ";
    }
    else if(this->method_type == BOOL)
    {
        cout<<"bool ";
    }
    cout<<this->method_name<<"(";

    list<Type>::iterator it1 = this->parameter_list_type->begin();
    list<string>::iterator it2 = this->parameter_list->begin();
    while(it1 != this->parameter_list_type->end() &&
          it2 != this->parameter_list->end())
    {
        Type t = *it1;
        if(t==INT)
        {
            cout<<"int ";
        }
        else if(t == BOOL)
        {
            cout<<"bool ";
        }
        string s = *it2;
        cout<<s;
        it1++;it2++;
        if(it1 != this->parameter_list_type->end())
            cout<<",";
    }
    cout<<")"<<endl;
    this->block->print();

}


newStatement* statementMethodecl::ValidarSemantica() {

    newStatement* block = this->block->ValidarSemantica();

    return block;
}
