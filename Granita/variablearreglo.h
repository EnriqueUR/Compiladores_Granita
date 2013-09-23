#ifndef VARIABLEARREGLO_H
#define VARIABLEARREGLO_H

#include "variable.h"
#include "newexpression.h"
#include "statementdeclaration.h"

class VariableArreglo: public Variable
{
public:
    VariableArreglo();
    VariableArreglo(statementDeclaration::Type tipo, newExpression* indice);
    newExpression* indice;
};

#endif // VARIABLEARREGLO_H
