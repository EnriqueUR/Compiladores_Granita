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
    newStatementFor(list<newStatementAssign*> *initialValues, newExpression *expr,
                    list<newStatementAssign*> *incrementValues, newStatementBlock *block);

protected:
    list<newStatementAssign*> *initialValues, incrementValues;
    newStatementBlock* block;
    newExpression* expression;
};

#endif // NEWSTATEMENTFOR_H
