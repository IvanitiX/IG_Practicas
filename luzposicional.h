#include "aux.h"
#include "luz.h"

class LuzPosicional:public Luz{
    public:
        LuzPosicional(const Tupla3f & punto, GLenum idLuz, Tupla4f difuso, Tupla4f especular,Tupla4f ambiente) ;
} ;