#ifndef SINGLETONTABLE_H
#define SINGLETONTABLE_H

#include "variable.h"
#include "procedimiento.h"

#include <map>
#include <iostream>

using namespace std;
class SingletonTable
{
public:
    map<string,Variable*> *TablaSimbolos;
    map<string, Procedimiento*> *Procedimientos;

    static SingletonTable* getInstance();
    Variable* getSimbolo(string nombre);
    void putSimbolo(string nombre, Variable* var);

    Procedimiento* getProcedimiento(string nombre);
    void putProcedimiento(string nombre, Procedimiento* var);
private:
    SingletonTable();
    static SingletonTable* pinstance;
};

#endif // SINGLETONTABLE_H
