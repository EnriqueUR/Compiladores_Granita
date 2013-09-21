#ifndef STATEMENTDECLARATION_H
#define STATEMENTDECLARATION_H

#include "statement.h"



class statementDeclaration:public statement
{
public:
    statementDeclaration();
    enum Type{INT,BOOL,VOID};
    void print();
};

#endif // STATEMENTDECLARATION_H
