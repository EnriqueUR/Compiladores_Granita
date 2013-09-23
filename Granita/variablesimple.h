#ifndef VARIABLESIMPLE_H
#define VARIABLESIMPLE_H

#include "variable.h"
#include "statementdeclaration.h"

class VariableSimple: public Variable
{
public:
    VariableSimple();
    VariableSimple(statementDeclaration::Type tipo);
};

#endif // VARIABLESIMPLE_H
