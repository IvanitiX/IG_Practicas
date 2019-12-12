#include "malla.h"
#include "aux.h"

/*Modelo jerárquico 1 : Flor*/
class Petalo{
    public:
        Petalo() ;
        void dibujar() ;
    private:
        Esfera * petEsfera = nullptr ;
};

class Tulipa{
    public:
        Tulipa() ;
        void dibujar() ;
        void caerPetalo(float incremento_x, float incremento_y) ;
    private:
        Petalo * tulPetaloAbajo = nullptr ;
        Petalo * tulPetaloIzq = nullptr ;
        Petalo * tulPetaloDer = nullptr ;
        Petalo * tulPetaloArriba = nullptr ;
        Esfera * tulCentro = nullptr ;
};

class Flor{
    public:
        Flor() ;
        void dibujar() ;
    private:
        Tulipa * florTulipa = nullptr ;
        Cilindro * florTallo = nullptr ;
        Esfera * florHoja = nullptr ;
} ;

/*Modelo jerárquico 2 : Ganso */

class Pierna{
    public:
        Pierna() ;
        void dibujar() ;
    private:
        Cubo * piePlanta = nullptr ;
        Cilindro * pieCilindro = nullptr ;
        Esfera * pieEsfera = nullptr ;
};

class Cuerpo{
    public:
        Cuerpo();
        void dibujar() ;
        void rotarPiernaDerecha(float incremento_z) ;
        void rotarPiernaIzquierda(float incremento_z) ;
    private:
        Pierna * cuerPieDer = nullptr ;
        Pierna * cuerPieIzq = nullptr ;
        Esfera * cuerCentro = nullptr ;
        Cono * cuerCola = nullptr ;
};

class Cabeza{
    public:
        Cabeza() ;
        void dibujar() ;
    private:
        Esfera * cabCentro = nullptr ;
        Esfera * cabOjoDer = nullptr ;
        Esfera * cabOjoIzq = nullptr ;
};

class Cuello{
    public:
        Cuello() ;
        void dibujar() ;
        void rotarCabeza(float incremento_x, float incremento_y, float incremento_z) ;
    private:
        Cabeza * cueCabeza = nullptr ;
        Esfera * cueRotacion = nullptr ; //Usado para fines de debug
        Cilindro * cueCentro = nullptr ;
};

class Ganso{
    public:
        Ganso() ;
        void dibujar() ;
        void rotarCuello(float incremento_x , float incremento_y) ;
    private:
        Cuerpo * ganCuerpo = nullptr ;
        Cuerpo * ganCuello = nullptr ;
} ;
