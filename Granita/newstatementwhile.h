#ifndef NEWSTATEMENTWHILE_H
#define NEWSTATEMENTWHILE_H

#include "newstatement.h"
#include "newexpression.h"
#include "newstatementblock.h"

class newStatementWhile:public newStatement
{
public:
    newStatementWhile(newExpression* condicion, newStatement* block);

protected:
    newExpression* condicion;
    newStatement* block;
};

#endif // NEWSTATEMENTWHILE_H
