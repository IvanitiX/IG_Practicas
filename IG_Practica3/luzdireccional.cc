#include "luzdireccional.h"

LuzDireccional::LuzDireccional(const Tupla2f & direccion,  
                                GLenum idLuz, Tupla4f difuso,
                                Tupla4f especular, Tupla4f ambiente){
    alfa = direccion[0] ;
    beta = direccion[1] ;
    Rotar() ;
    id = idLuz ;
    colorDifuso = difuso ;
    colorEspecular = especular ;
    colorAmbiente = ambiente ;
    tipo = 1 ;
}

void LuzDireccional::variarAnguloAlfa(float incremento){
    alfa += incremento ;
    alfa = (float) ((int)alfa%360) ;
    this->Rotar() ;
    std::cout << "Alfa : " << alfa << " Beta : " << beta <<  " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}


void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento ;
    beta = (float) ((int)beta%360) ;
    this->Rotar() ;
    std::cout << "Alfa : " << alfa << " Beta : " << beta << " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}

void LuzDireccional::Rotar(){
    int radio = 202 ;
    posicion[0] = radio*sin(alfa)*cos(beta) ;
    posicion[1] = radio*sin(alfa)*sin(beta) ;
    posicion[2] = radio*cos(alfa) ;
    posicion[3] = 0.0 ;
}

void LuzDireccional::activar(){
    glLightfv(id, GL_AMBIENT, colorAmbiente) ;
    glLightfv(id, GL_SPECULAR, colorEspecular) ;
    glLightfv(id, GL_DIFFUSE, colorDifuso) ;
    glLightfv(id,GL_POSITION,posicion) ;
    glEnable(GL_LIGHTING) ;
    glEnable(id) ;
}
