#ifndef SINGLETONTABLE_H
#define SINGLETONTABLE_H

#include <list>

class SingletonTable
{
public:
      static SingletonTable* Instance();
   protected:
      Singleton();
      Singleton(const SingletonTable & ) ;
      SingletonTable &operator= (const SingletonTable &) ;
   private:
      static SingletonTable* pinstance;
};

#endif // SINGLETONTABLE_H
