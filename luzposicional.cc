#include "luzposicional.h"
LuzPosicional::LuzPosicional(const Tupla3f & punto, GLenum idLuz, 
                            Tupla4f difuso, Tupla4f especular,
                            Tupla4f ambiente){
    posicion[0] = punto[0];
    posicion[1] = punto[1];
    posicion[2] = punto[2];
    posicion[3] = 1;

    id = idLuz ;
    colorAmbiente = ambiente ;
    colorDifuso = difuso ;
    colorEspecular = especular ;

    tipo = 2 ;
    altura = 0.0 ;
    sentido = true ;
}

void LuzPosicional::translacion(int incremento_y){
    if(altura <= 0) {altura+=incremento_y ; sentido = true ;} 
    else if(altura >= 10) {altura-=incremento_y ; sentido = false ;}
    sentido ? altura+=incremento_y : altura-=incremento_y ;
}

float LuzPosicional::getAltura(){ return altura ; }