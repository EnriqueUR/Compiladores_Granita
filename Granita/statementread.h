#ifndef STATEMENTREAD_H
#define STATEMENTREAD_H
#include <list>
#include "exprlvalue.h"
#include "statement.h"

#include "newstatement.h"
#include "newstatementread.h"
#include "newexprlvalue.h"

using namespace std;
class statementRead:public statement
{
public:
    statementRead(list<exprLvalue*> *lvalue, int linea);
    newStatement * ValidarSemantica();

    void print();
private:
    list<exprLvalue*> *lvalue;

};

#endif // STATEMENTREAD_H
