#ifndef LEXICO_H
#define LEXICO_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include "token.h"

using namespace std;
class lexico
{
public:
    lexico(char* file);
    Token* NexToken();
    int length_cadena;
    int linea;
private:
    int posc;
    void ungetc();
    string isreserved(string id);
    char NextSymbol();
    void getc();
    char CS;
    list<string> reservados;
    FILE *F;
    string lexema;
    string cadena_entrada;

};

#endif // LEXICO_H
