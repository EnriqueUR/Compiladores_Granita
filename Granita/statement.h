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
<<<<<<< HEAD
    virtual newStatement *validarSemantica();
    virtual PrintError(string msj);
=======
    virtual newStatement *ValidarSemantica();
    virtual void PrintError(string msj);
>>>>>>> f120c4fc22361d1debd8011e664e906ef9d2f3c8
};

#endif // STATEMENT_H
