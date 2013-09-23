#ifndef STATEMENTBREAK_H
#define STATEMENTBREAK_H

#include "statement.h"
#include "newstatementbreak.h"

#include "analisissemantico.h"

class statementBreak : public statement
{
public:
    statementBreak(int linea);
    newStatement * ValidarSemantica();
    void print();

};

#endif // STATEMENTBREAK_H
