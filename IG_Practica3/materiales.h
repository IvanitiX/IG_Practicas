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