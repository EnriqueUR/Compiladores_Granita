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
