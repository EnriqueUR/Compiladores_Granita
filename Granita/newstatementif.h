#ifndef NEWSTATEMENTIF_H
#define NEWSTATEMENTIF_H

#include "newstatement.h"
#include "newstatementblock.h"
#include "newexpression.h"

class newStatementIf: public newStatement
{
public:
    newStatementIf(newExpression* expresion, newStatement* trueBlock,
                   newStatement* falseBlock);
    newStatementIf(newExpression *expresion, newStatement *trueBlock);

protected:
    newExpression* expresion;
    newStatement* trueBlock, *falseBlock;
};

#endif // NEWSTATEMENTIF_H
