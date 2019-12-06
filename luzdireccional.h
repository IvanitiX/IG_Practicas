#include "aux.h"
#include "luz.h"

class LuzDireccional: public Luz{
    public:
        LuzDireccional(const Tupla2f & direccion, GLenum idLuz, Tupla4f difuso, Tupla4f especular, Tupla4f ambiente) ;
        void variarAnguloAlfa(float incremento) ;
        void variarAnguloBeta(float incremento) ;
        void Rotar() ;
        void activar() ;
    protected:
        float alfa = 0.0 ;
        float beta = 0.0 ;
} ;