#include "singletontable.h"

SingletonTable* SingletonTable::pinstance = 0;// Inicializar el puntero
SingletonTable* SingletonTable::getInstance ()
{
  if (pinstance == 0)  // ¿Es la primera llamada?
  {
    pinstance = new SingletonTable(); // Creamos la instancia
  }
  return pinstance; // Retornamos la dirección de la instancia
}
SingletonTable::SingletonTable()
{
    TablaSimbolos = new map<string,Variable*>();
    Procedimientos = new map<string, Procedimiento*>();
}

Variable* SingletonTable::getSimbolo(string nombre) {
    if (TablaSimbolos->count(nombre) > 0) {
        return TablaSimbolos->at(nombre);
    }
    return NULL;
}

void SingletonTable::putSimbolo(string nombre, Variable *var) {
    TablaSimbolos->insert(pair<string, Variable*>(nombre, var));
}

Procedimiento* SingletonTable::getProcedimiento(string nombre) {
    if (Procedimientos->count(nombre) > 0) {
        return Procedimientos->at(nombre);
    }
    return NULL;
}

void SingletonTable::putProcedimiento(string nombre, Procedimiento *var) {
    Procedimientos->insert(pair<string, Procedimiento*>(nombre, var));
}
