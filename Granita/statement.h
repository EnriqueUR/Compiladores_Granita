#ifndef STATEMENT_H
#define STATEMENT_H
#include <iostream>
#include "newstatement.h"

using namespace std;
class statement
{
public:
    statement();
    virtual void print() = 0;
    int Linea;

    virtual newStatement *ValidarSemantica();
    virtual void PrintError(string msj);
};

#endif // STATEMENT_H
