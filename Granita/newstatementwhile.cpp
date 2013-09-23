#include "newstatementwhile.h"

newStatementWhile::newStatementWhile(newExpression *condicion, newStatementBlock *block)
{
    this->condicion = condicion;
    this->block = block;
}
