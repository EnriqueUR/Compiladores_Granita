#ifndef STATEMENTBLOCK_H
#define STATEMENTBLOCK_H
#include "statement.h"
#include "var_decl.h"
#include <list>

using namespace std;
class statementBlock:public statement
{
public:
    statementBlock(list<var_decl*> *vars,list<statement*> *sentences, int linea);
    void print();
private:
    list<var_decl*> *vars;
    list<statement*> *sentences;
};

#endif // STATEMENTBLOCK_H
