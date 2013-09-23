#ifndef NEWSTATEMENTPRINT_H
#define NEWSTATEMENTPRINT_H

#include <list>

#include "newstatement.h"
#include "newexprargument.h"

class newStatementPrint: public newStatement
{
public:
    newStatementPrint(list<newExprArgument*> *newArgs);

protected:
    list<newExprArgument*> *newArgs;
};

#endif // NEWSTATEMENTPRINT_H
