#include "newstatementif.h"

newStatementIf::newStatementIf(newExpression *expresion, newStatement *trueBlock)
{
    this->expresion = expresion;
    this->trueBlock = trueBlock;
    this->falseBlock = NULL;
}

newStatementIf::newStatementIf(newExpression *expresion,
                               newStatement *trueBlock, newStatement *falseBlock)
{
    this->expresion = expresion;
    this->trueBlock = trueBlock;
    this->falseBlock = falseBlock;
}
