#include "tuplasg.h"
#include "aux.h"

#ifndef LUZ
#define LUZ

class Luz {
    public:
        void activar() ;
        void desactivar() ;
    protected:
        Tupla4f posicion;
        GLenum id ;
        Tupla4f colorAmbiente ;
        Tupla4f colorDifuso ;
        Tupla4f colorEspecular ;
} ;

#endif