#ifndef STATEMENTPRINT_H
#define STATEMENTPRINT_H
#include <list>
#include "statement.h"
#include "exprargument.h"

using namespace std;
class statementPrint:public statement
{
public:
    statementPrint(list<exprArgument*> *arguments);
    void print();
private:
    list<exprArgument*> *arguments;

};

#endif // STATEMENTPRINT_H
