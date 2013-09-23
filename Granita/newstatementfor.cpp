#include "newstatementfor.h"

newStatementFor::newStatementFor(list<newStatementAssign *> *initialValues,
                                 newExpression *expr,
                                 list<newStatementAssign *> *incrementValues,
                                 newStatementBlock *block)
{
    this->initialValues = initialValues;
    this->expression = expr;
    this->incrementValues = incrementValues;
    this->block = block;
}
