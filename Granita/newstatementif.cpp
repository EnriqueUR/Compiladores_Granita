#include "newstatementif.h"

newStatementIf::newStatementIf(newExpression *expresion, newStatementBlock *trueBlock)
{
    this->expresion = expresion;
    this->trueBlock = trueBlock;
    this->falseBlock = NULL;
}

newStatementIf::newStatementIf(newExpression *expresion,
                               newStatementBlock *trueBlock,
                               newStatementBlock *falseBlock)
{
    this->expresion = expresion;
    this->trueBlock = trueBlock;
    this->falseBlock = falseBlock;
}
