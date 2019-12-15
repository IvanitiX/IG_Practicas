#include "objrevolucion.h"

#ifndef ESFERA
#define ESFERA
class Esfera:public ObjRevolucion{
    public:
    Esfera(const int num_vert_perfil,const int num_instancias_perf,const float radio);
} ;
#endif