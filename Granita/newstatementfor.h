#ifndef NEWSTATEMENTFOR_H
#define NEWSTATEMENTFOR_H

#include <list>

#include "newstatement.h"
#include "newstatementassign.h"
#include "newexpression.h"
#include "newstatementblock.h"

class newStatementFor: public newStatement
{
public:
    newStatementFor(list<newStatement*> *initialValues, newExpression *expr,
                    list<newStatement*> *incrementValues, newStatement *block);

protected:
    list<newStatement*> *initialValues, *incrementValues;
    newStatement* block;
    newExpression* expression;
};

#endif // NEWSTATEMENTFOR_H
