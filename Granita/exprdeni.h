#ifndef EXPRDENI_H
#define EXPRDENI_H
#include "unaryexpr.h"
#include "newexpression.h"
#include "newexprdeni.h"

class exprDeni:public unaryExpr
{
public:
    exprDeni();
    exprDeni(Expression *expr, int linea);
    newExpression *ValidarSermantica();
    void print();
    void PrintError(string msj);

};

#endif // EXPRDENI_H
