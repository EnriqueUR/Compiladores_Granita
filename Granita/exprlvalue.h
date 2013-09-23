#ifndef EXPRLVALUE_H
#define EXPRLVALUE_H
#include <iostream>
#include "expression.h"
#include "newexprlvalue.h"

using namespace std;
class exprLvalue: public Expression
{
public:
    exprLvalue(int linea);
    exprLvalue(string id, int linea);
    exprLvalue(string id,Expression *expr, int linea);
    newExpression *ValidarSermantica();
    string getId();
    void print();
    void PrintError(string msj);
    void setExpr(Expression *expr);
    void setId(string id);

//private:
    string id;
    Expression *expr;
};

#endif // EXPRLVALUE_H
