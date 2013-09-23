#ifndef SINGLETONTABLE_H
#define SINGLETONTABLE_H
#include "variable.h"
#include <map>
#include <iostream>
using namespace std;
class SingletonTable
{
public:
    map<string,Variable*> *TablaSimbolos;
    static SingletonTable* getInstance();
    Variable* getSimbolo(string nombre);
    void putSimbolo(string nombre, Variable* var);
private:
    SingletonTable();
    static SingletonTable* pinstance;
};

#endif // SINGLETONTABLE_H
