#ifndef NEWSTATEMENTREAD_H
#define NEWSTATEMENTREAD_H

#include <list>

#include "newstatement.h"
#include "newexprlvalue.h"

class newStatementRead: public newStatement
{
public:
    newStatementRead(list<newExprLvalue*> * args);

protected:
    list<newExprLvalue*> * args;
};

#endif // NEWSTATEMENTREAD_H
