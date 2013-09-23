#ifndef NEWPROGRAM_H
#define NEWPROGRAM_H

#include "newstatement.h"

class newProgram
{
public:
    newProgram(newStatement* main);

private:
    newStatement* main;
};

#endif // NEWPROGRAM_H
