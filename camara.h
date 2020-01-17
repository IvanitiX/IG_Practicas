#include "aux.h"

#ifndef CAMARA
#define CAMARA
class Camara{
    protected :
        const float PI = 3.14159265358979;
        Tupla3f eye, at, up ;
        int tipo ;
        float left,right,top,bottom,near,far ;
        float distanciaObs ;
    public :
        Camara(Tupla3f cameye, Tupla3f camat, Tupla3f camup, int camtipo, float camizq, float camder, float camcer, float camlej, float camarr, float camaba) ;
        //Usar si tenemos algo seleccionado
        void rotarXExaminar(float anguloX) ;
        void rotarYExaminar(float anguloY) ;
        void rotarZExaminar(float anguloZ) ;
        //Usar cuando no estemos seleccionando algo
        void rotarXFirstPerson(float anguloX) ;
        void rotarYFirstPerson(float anguloY) ;
        void rotarZFirstPerson(float anguloZ) ;
        //Otros
        void mover (float x, float y, float z) ;
        void zoom (float factor) ;
        void girar(float x, float y) ;
        //Setters
        void setObserver() ;
        void setProyeccion() ;
        void setAt(Tupla3f newat) ;
} ;
#endif