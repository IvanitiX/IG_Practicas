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
}