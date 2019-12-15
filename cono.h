#include "objrevolucion.h"
#include "aux.h"
#include "malla.h"

#ifndef CONO
#define CONO

class Cono:public ObjRevolucion{
    public:
    Cono(const int num_vert_perfil,const int num_instancias_perf, const float altura,const float radio);
} ;

#endif