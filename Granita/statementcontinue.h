#ifndef STATEMENTCONTINUE_H
#define STATEMENTCONTINUE_H

#include "statement.h"

class statementContinue: public statement
{
public:
    statementContinue(int linea);
    void print();
};

#endif // STATEMENTCONTINUE_H
