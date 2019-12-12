#include "tuplasg.h"
#include "aux.h"


#ifndef MATERIAL
#define MATERIAL

class Material{
    protected:
        Tupla4f colorMatDifuso;
        Tupla4f especular;
        Tupla4f ambiente ;
        float brillo ;
    public:
        Material (Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float brillo) ;
        void aplicar() ;
} ;

#endif