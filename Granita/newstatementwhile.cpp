#include "newstatementwhile.h"

newStatementWhile::newStatementWhile(newExpression *condicion, newStatement *block)
{
    this->condicion = condicion;
    this->block = block;
}
