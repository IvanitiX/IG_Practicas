#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil,const int num_instancias_perf,const float altura,const float radio){
      std::vector<Tupla3f> perfil;
  perfil.push_back({0,0,0}) ;
  for ( unsigned i = 0; i <= num_vert_perfil; i++){
    perfil.push_back( {radio, 0.0 + altura*(i*1.0/num_vert_perfil), 0.0}); 
   }
  perfil.push_back({0,altura,0}) ;

  std::vector<Tupla3f> perfilAlt = ObjRevolucion::formatoPerfil(perfil) ;
  ObjRevolucion::crearMalla(perfilAlt, num_instancias_perf, true, true) ;

  solido = {0.5,0.5,0} ;
  puntos = {1,0,0} ;
  linea = {0,0,0} ;

  color_impar_ajedrez = {0.5,0.5,0} ;
  color_par_ajedrez = {0,0,0} ;

  MaterialAmarillo * ma = new MaterialAmarillo() ;
  material = ma ;
}