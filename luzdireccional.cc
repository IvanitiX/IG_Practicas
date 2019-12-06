#include "luzdireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & direccion,  
                                GLenum idLuz, Tupla4f difuso,
                                Tupla4f especular, Tupla4f ambiente){
    posicion[0] = direccion[0] ;
    posicion[1] = direccion[1] ;
    posicion[2] = 0 ;
    posicion[3] = 0 ;

    id = idLuz ;
    colorDifuso = difuso ;
    colorEspecular = especular ;
    colorAmbiente = ambiente ;
}

void LuzDireccional::variarAnguloAlfa(float incremento){
    alfa += incremento ;
    EsfericasACartesianas() ;
    std::cout << "Alfa : " << alfa << " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}


void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento ;
    EsfericasACartesianas() ;
    std::cout << "Beta : " << beta << " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}

void LuzDireccional::EsfericasACartesianas(){
    float radio = 202.0 ;
    posicion[0] = posicion[0]*radio*sin(alfa)*cos(beta) ;
    posicion[1] = posicion[1]*radio*sin(alfa)*sin(beta) ;
    posicion[2] = radio*cos(beta) ;
}
