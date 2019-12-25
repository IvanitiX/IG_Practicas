#include "cuadro.h"

Cuadro::Cuadro(){
    v = {{-0.5,0,-0.5}, {0.5,0,-0.5}, {-0.5,0,0.5}, {0.5,0,0.5}} ;
    f = {{0,2,1},{1,2,3}} ;
    ct = {{0,1},{1,1},{0,0},{1,0}} ;
    puntos = {1,1,1} ;
    linea = {0,0,0} ;
    material = new MaterialBlanco ;
}