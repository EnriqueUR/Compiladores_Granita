#ifndef PROGRAM_H
#define PROGRAM_H
#include <list>
#include "statementfieldecl.h"
#include "statementmethodecl.h"
class program
{
public:
    program(string id,list<statementMethodecl*> *methods, list<statementFieldecl*> *field);
    void print();
private:
    string id;
    list<statementMethodecl*> *methods;
    list<statementFieldecl*> *field;
};

#endif // PROGRAM_H
