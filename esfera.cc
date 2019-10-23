#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil,const int num_instancias_perf,const float radio){
    std::vector<Tupla3f> perfil;

  for ( float i = 0.0; i <= num_vert_perfil; i+=1.0){
      float y = -radio + 2*radio*(i/num_vert_perfil);
      float x = sqrt(radio*radio - y*y) ;
    perfil.push_back( {x, 0.0 + y, 0.0});
  }
  

  ObjRevolucion::crearMalla(perfil, num_instancias_perf) ;

  for(unsigned i = 0 ; i < v.size() ; i++){
    colores_solido.push_back({0,0.82,0.5}) ;
    colores_puntos.push_back({127,127,0}) ;
    colores_linea.push_back({0,0,0}) ;
  }
}