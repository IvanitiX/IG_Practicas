#include "objrevolucion.h"

#ifndef CILINDRO
#define CILINDRO
class Cilindro:public ObjRevolucion{
    public:
    Cilindro(const int num_vert_perfil,const int num_instancias_perf,const float altura,const float radio);
} ;
#endif