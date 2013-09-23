#ifndef PROCEDIMIENTO_H
#define PROCEDIMIENTO_H

#include "newstatementblock.h"

class Procedimiento
{
public:
    Procedimiento(newStatementBlock* block);

protected:
    newStatementBlock* block;
};

#endif // PROCEDIMIENTO_H
