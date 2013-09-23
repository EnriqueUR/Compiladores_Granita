#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lexico.h"
#include "token.h"
#include "sintactico.h"

using namespace std;
int main()
{
    sintactico *S = new sintactico("program10.txt");
    program *p;
    p = S->Program();
    p->print();
    system("pause");
}
