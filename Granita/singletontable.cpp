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
    TablaSimbolos = new map<string,Variable>();
}
