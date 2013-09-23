#ifndef NEWSTATEMENTIF_H
#define NEWSTATEMENTIF_H

#include "newstatement.h"
#include "newstatementblock.h"
#include "newexpression.h"

class newStatementIf: public newStatement
{
public:
    newStatementIf(newExpression* expresion, newStatementBlock* trueBlock,
                   newStatementBlock* falseBlock);
    newStatementIf(newExpression *expresion, newStatementBlock *trueBlock);

protected:
    newExpression* expresion;
    newStatementBlock* trueBlock, *falseBlock;
};

#endif // NEWSTATEMENTIF_H
