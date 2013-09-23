#include "newstatementfor.h"

newStatementFor::newStatementFor(list<newStatement *> *initialValues,
                                 newExpression *expr,
                                 list<newStatement *> *incrementValues,
                                 newStatement *block)
{
    this->initialValues = initialValues;
    this->expression = expr;
    this->incrementValues = incrementValues;
    this->block = block;
}
