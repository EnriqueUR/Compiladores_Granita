#include "variablearreglo.h"

VariableArreglo::VariableArreglo(statementDeclaration::Type tipo, newExpression *indice)
{
    this->tipo = tipo;
    this->indice = indice;
}
