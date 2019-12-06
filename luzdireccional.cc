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
    alfa = (float) ((int)alfa%360) ;
    //this->Rotar() ;
    std::cout << "Alfa : " << alfa << " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}


void LuzDireccional::variarAnguloBeta(float incremento){
    beta += incremento ;
    beta = (float) ((int)beta%360) ;
    //this->Rotar() ;
    std::cout << "Beta : " << beta << " - X/Y/Z : " << posicion[0] << "/" << posicion[1] << "/" << posicion[2] << std::endl ;
    this->activar() ;
}

void LuzDireccional::Rotar(){
    posicion[0] = posicion[0] + cos(beta)*posicion[0] ;
    posicion[1] = posicion[1] + cos(alfa)*posicion[1] ;
}

void LuzDireccional::activar(){
    glLightfv(id, GL_AMBIENT, colorAmbiente) ;
    glLightfv(id, GL_SPECULAR, colorEspecular) ;
    glLightfv(id, GL_DIFFUSE, colorDifuso) ;
    glRotatef(alfa,0.0,1.0,0.0) ;
    glRotatef(beta,-1.0,0.0,0.0) ;
    glLightfv(id,GL_POSITION,posicion) ;
    glEnable(GL_LIGHTING) ;
    glEnable(id) ;
}
