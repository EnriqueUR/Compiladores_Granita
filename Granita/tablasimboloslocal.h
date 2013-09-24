#ifndef TABLASIMBOLOSLOCAL_H
#define TABLASIMBOLOSLOCAL_H

#include "variablesimple.h"
#include <map>

class TablaSimbolosLocal
{
public:
    TablaSimbolosLocal();
    map<string,VariableSimple*> *TablaSimbolos;

    VariableSimple* getSimbolo(string nombre);
    void putSimbolo(string nombre, VariableSimple* var);

};

#endif // TABLASIMBOLOSLOCAL_H
