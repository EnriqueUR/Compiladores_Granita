#ifndef ANALISISSEMANTICO_H
#define ANALISISSEMANTICO_H

#include "tablasimboloslocal.h"

class AnalisisSemantico
{
public:
    AnalisisSemantico();
    static bool dentroCiclo;
    static TablaSimbolosLocal* tablaActual;
};

#endif // ANALISISSEMANTICO_H
