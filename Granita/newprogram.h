#ifndef NEWPROGRAM_H
#define NEWPROGRAM_H

#include "newstatementblock.h"

class newProgram
{
public:
    newProgram(newStatementBlock* main);

private:
    newStatementBlock* main;
};

#endif // NEWPROGRAM_H
