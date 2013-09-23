#ifndef STATEMENTPRINT_H
#define STATEMENTPRINT_H
#include <list>
#include "statement.h"
#include "exprargument.h"

#include "newstatement.h"
#include "newstatementprint.h"
#include "newexpression.h"

using namespace std;
class statementPrint:public statement
{
public:
    statementPrint(list<exprArgument*> *arguments, int linea);
    newStatement * ValidarSemantica();
    void print();

private:
    list<exprArgument*> *arguments;

};

#endif // STATEMENTPRINT_H
