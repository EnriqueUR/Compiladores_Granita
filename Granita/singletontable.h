#ifndef SINGLETONTABLE_H
#define SINGLETONTABLE_H
#include "variable.h"
#include <map>
#include <iostream>
using namespace std;
class SingletonTable
{
public:
      static SingletonTable* Instance();
      map<string,Variable> *TablaSimbolos;
   protected:
      SingletonTable();
      SingletonTable(const SingletonTable & ) ;
      SingletonTable &operator= (const SingletonTable &);
   private:
      static SingletonTable* pinstance;
};

#endif // SINGLETONTABLE_H
