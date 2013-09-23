#ifndef STATEMENTCONTINUE_H
#define STATEMENTCONTINUE_H

#include "newstatementcontinue.h"
#include "statement.h"

class statementContinue: public statement
{
public:
    statementContinue(int linea);
    newStatement* ValidarSemantica();
    void print();

};

#endif // STATEMENTCONTINUE_H
