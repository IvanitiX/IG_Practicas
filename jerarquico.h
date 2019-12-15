#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cono.h"
#include "cilindro.h"
#include "esfera.h"
#include "aux.h"

/*Modelo jerárquico 1 : Flor*/
class Petalo: public Malla3D{
    public:
        Petalo() ;
        void draw(int modo, bool modoDib) ;
        void setColorPetalo(Tupla3f color) ;
    protected:
        Esfera * petEsfera = nullptr ;
};

class Tulipa: public Malla3D{
    public:
        Tulipa() ;
        void draw(int modo, bool modoDib) ;
        void caerPetalo(float incremento_x, float incremento_y) ;
    protected:
        Petalo * tulPetaloAbajo = nullptr ;
        Petalo * tulPetaloIzq = nullptr ;
        Petalo * tulPetaloDer = nullptr ;
        Petalo * tulPetaloArriba = nullptr ;
        Esfera * tulCentro = nullptr ;

        float caidaPetaloX, caidaPetaloY ;
};

class Flor: public Malla3D{
    public:
        Flor() ;
        void draw(int modo, bool modoDib) ;
        void caerPetalo(float incremento_x, float incremento_y) ;
    protected:
        Tulipa * florTulipa = nullptr ;
        Cilindro * florTallo = nullptr ;
        Esfera * florHoja = nullptr ;
} ;

/*Modelo jerárquico 2 : Ganso */

class Pierna: public Malla3D{
    public:
        Pierna() ;
        void draw(int modo, bool modoDib) ;
    protected:
        Cubo * piePlanta = nullptr ;
        Cilindro * pieCilindro = nullptr ;
        Esfera * pieEsfera = nullptr ;
};

class Cuerpo: public Malla3D{
    public:
        Cuerpo();
        void draw(int modo, bool modoDib) ;
        void rotarPiernaDerecha(float incremento_z) ;
        void rotarPiernaIzquierda(float incremento_z) ;
    protected:
        Pierna * cuerPieDer = nullptr ;
        Pierna * cuerPieIzq = nullptr ;
        Esfera * cuerCentro = nullptr ;
        Cono * cuerCola = nullptr ;

        float rotacionAlfa, rotacionOmega ;
};

class Cabeza: public Malla3D{
    public:
        Cabeza() ;
        void draw(int modo, bool modoDib) ;
        void caerPetalo(float incremento_x, float incremento_y) ;
        
    protected:
        Esfera * cabCentro = nullptr ;
        Esfera * cabOjoDer = nullptr ;
        Esfera * cabOjoIzq = nullptr ;
        Tetraedro * cabPico = nullptr ;
        Flor * cabFlor = nullptr ;
};

class Cuello: public Malla3D{
    public:
        Cuello() ;
        void draw(int modo, bool modoDib) ;
        void caerPetalo(float incremento_x, float incremento_y) ;
        void rotarCabeza(float incremento_x, float incremento_y, float incremento_z) ;
    protected:
        Cabeza * cueCabeza = nullptr ;
        Esfera * cueRotacion = nullptr ; //Usado para fines de debug
        Cilindro * cueCentro = nullptr ;

        float rotacionDelta, rotacionEpsilon, rotacionChi ;
};

class Ganso: public Malla3D{
    public:
        Ganso() ;
        void draw(int modo, bool modoDib) ;
        void rotarCuello(float incremento_x , float incremento_y) ;
        void rotarCabeza(float incremento_x, float incremento_y, float incremento_z) ;
        void caerPetalo(float incremento_x, float incremento_y) ;
        void rotarPiernaDerecha(float incremento_z) ;
        void rotarPiernaIzquierda(float incremento_z) ;
    protected:
        Cuerpo * ganCuerpo = nullptr ;
        Cuello * ganCuello = nullptr ;

        float rotacionBeta, rotacionGamma ;
} ;
