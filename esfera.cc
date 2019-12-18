#include "esfera.h"

Esfera::Esfera(const int num_vert_perfil,const int num_instancias_perf,const float radio){
    std::vector<Tupla3f> perfil;

  perfil.push_back({0,-radio,0});
  for ( int i = 1; i <= num_vert_perfil  ; i++){
      float y = -radio + 2*radio*(i*1.0/num_vert_perfil);
      float x = sqrt(radio*radio - y*y) ;
    perfil.push_back( {x, y, 0.0});
  }
  perfil.push_back({0,radio,0}) ;

  std::vector<Tupla3f> perfilAlt = ObjRevolucion::formatoPerfil(perfil) ;
  ObjRevolucion::crearMalla(perfilAlt, num_instancias_perf,true,true) ;

  solido = {0,0.82,0.5} ;
  linea = {0.5,0.5,0} ;
  puntos = {0,0,0} ;

  color_impar_ajedrez = {0,0.82,0.5} ;
  color_par_ajedrez = {0,0,0} ;

  MaterialMagenta * mm = new MaterialMagenta() ;
  material = mm ;
}