#ifndef STATEMENTBREAK_H
#define STATEMENTBREAK_H

#include "statement.h"
#include "newstatementbreak.h"

class statementBreak : public statement
{
public:
    statementBreak(int linea);
    void print();
};

#endif // STATEMENTBREAK_H
