#include "program.h"

program::program(string id, list<statementMethodecl *> *methods, list<statementFieldecl *> *field) {
    this->id = id;
    this->methods = methods;
    this->field = field;
}
void program::print()
{
    cout<<"class";
    cout<<this->id<<"{"<<endl;
    list<statementMethodecl*>::iterator it1;
    it1 = this->methods->begin();
    list<statementFieldecl*>::iterator it2;
    it2 = this->field->begin();
    while(it2 != this->field->end())
    {
        statementFieldecl *m;
        m = *it2;
        m->print();
        cout<<endl;
        it2++;
    }

    while(it1 != this->methods->end())
    {
        statementMethodecl *m;
        m = *it1;
        m->print();
        cout<<endl;
        it1++;
    }


    cout<<"}";
}


newProgram* program::ValidarSemantica() {
    list<statementFieldecl*>::iterator it2;
    it2 = this->field->begin();
    while(it2 != this->field->end())
    {
        statementFieldecl *m;
        m = *it2;
        if (m->ValidarSemantica() == NULL) {
            return NULL;
        }
        it2++;
    }

    newStatementBlock* main = NULL;

    list<statementMethodecl*>::iterator it1;
    it1 = this->methods->begin();
    while(it1 != this->methods->end())
    {
        statementMethodecl *m;
        m = *it1;

        newStatement* newM = m->ValidarSemantica();
        if (newM == NULL) {
            return NULL;
        }

        if (m->method_name == "main") {
            main = newM;
        }
        it1++;
    }

    return new newProgram(main);
}
