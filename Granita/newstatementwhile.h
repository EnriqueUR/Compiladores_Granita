#ifndef NEWSTATEMENTWHILE_H
#define NEWSTATEMENTWHILE_H

#include "newstatement.h"
#include "newexpression.h"
#include "newstatementblock.h"

class newStatementWhile
{
public:
    newStatementWhile(newExpression* condicion, newStatementBlock* block);

protected:
    newExpression* condicion;
    newStatementBlock* block;
};

#endif // NEWSTATEMENTWHILE_H
