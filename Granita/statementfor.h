#ifndef STATEMENTFOR_H
#define STATEMENTFOR_H
#include <list>
#include "statement.h"
#include "expression.h"
#include "statementassign.h"
#include "statementblock.h"

#include "newstatementfor.h"
#include "analisissemantico.h"

class statementFor:public statement
{
public:
    statementFor(list<statementAssign*> *initialValues,Expression *expr,
                 list<statementAssign*> *incrementValues,statementBlock *block, int linea);
    newStatement* ValidarSemantica();
    void print();
private:
    Expression *expr;
    list<statementAssign*> *initialValues;
    list<statementAssign*> *incrementValues;
    statementBlock *block;
};

#endif // STATEMENTFOR_H
