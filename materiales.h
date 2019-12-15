#include "material.h"
#include "aux.h"
#include "tuplasg.h"

#ifndef CIAN
#define CIAN
class MaterialCian : public Material{
    public:
    MaterialCian() ;
} ;
#endif

#ifndef AMARILLO
#define AMARILLO
class MaterialAmarillo : public Material{
    public:
    MaterialAmarillo() ;
} ;
#endif

#ifndef MAGENTA
#define MAGENTA
class MaterialMagenta : public Material{
    public:
    MaterialMagenta() ;
} ;
#endif

#ifndef ULTRADIFUSO
#define ULTRADIFUSO
    class MaterialUltraDifuso : public Material{
        public:
            MaterialUltraDifuso() ;
    } ;
#endif


#ifndef ULTRAESPECULAR
#define ULTRAESPECULAR
    class MaterialUltraEspecular : public Material{
        public:
            MaterialUltraEspecular() ;
    } ;
#endif

#ifndef NARANJA
#define NARANJA
    class MaterialNaranja : public Material{
        public:
            MaterialNaranja() ;
    } ;
#endif

#ifndef NEGRO
#define NEGRO
    class MaterialNegro : public Material{
        public:
            MaterialNegro() ;
    } ;
#endif

#ifndef BLANCO
#define BLANCO
    class MaterialBlanco : public Material{
        public:
            MaterialBlanco() ;
    } ;
#endif

#ifndef VERDE
#define VERDE
    class MaterialVerde : public Material{
        public:
            MaterialVerde() ;
    } ;
#endif