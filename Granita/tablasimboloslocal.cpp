#include "tablasimboloslocal.h"

TablaSimbolosLocal::TablaSimbolosLocal()
{
    this->TablaSimbolos = new map<string, VariableSimple*>();
}

VariableSimple* TablaSimbolosLocal::getSimbolo(string nombre) {
    if (TablaSimbolos->count(nombre) > 0) {
        return TablaSimbolos->at(nombre);
    }
    return NULL;
}

void TablaSimbolosLocal::putSimbolo(string nombre, VariableSimple *var) {
    TablaSimbolos->insert(pair<string, VariableSimple*>(nombre, var));
}
