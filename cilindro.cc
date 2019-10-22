#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil,const int num_instancias_perf,const float altura,const float radio){
      std::vector<Tupla3f> perfil;
  //perfil.push_back({0,0,0}) ;
  for ( unsigned i = 0; i <= num_vert_perfil; i+=1){
    perfil.push_back( {radio, 0.0 + altura*(i*1.0/num_vert_perfil), 0.0});  }
  ObjRevolucion::crearMalla(perfil, num_instancias_perf, true, true) ;
}