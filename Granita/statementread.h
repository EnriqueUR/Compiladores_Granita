#ifndef STATEMENTREAD_H
#define STATEMENTREAD_H
#include <list>
#include "exprlvalue.h"
#include "statement.h"

using namespace std;
class statementRead:public statement
{
public:
    statementRead(list<exprLvalue*> *lvalue, int linea);
    void print();
private:
    list<exprLvalue*> *lvalue;

};

#endif // STATEMENTREAD_H
