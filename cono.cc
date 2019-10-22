#include "cono.h"

Cono::Cono(const int num_vert_perfil,const int num_instancias_perf, const float altura,const float radio){
  std::vector<Tupla3f> perfil;
  //perfil.push_back({0,0,0});
  for ( float i = 0.0; i <= num_vert_perfil; i+=1.0){
    perfil.push_back( {radio - radio*(i/num_vert_perfil), 0.0 + altura*(i/num_vert_perfil), 0.0});
  }
  ObjRevolucion::crearMalla(perfil, num_instancias_perf, false, true) ;
}