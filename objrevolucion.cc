#include "aux.h"
#include "objrevolucion.h"
#include <iostream>




// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
   // completar ......(práctica 2)
   ply::read_vertices( archivo, this->v);
       std::vector<Tupla3f> formato ;
    for(int i = 0 ; i < v.size() ; i++){
       formato.push_back(v[i]) ;
    }
    formato.push_back({0,v[0][1],0}) ;
    formato.push_back({0,v[v.size()-1][1],0}) ;
   crearMalla(formato,num_instancias,tapa_sup,tapa_inf);
   for(unsigned i = 0 ; i < v.size() ; i++){
    colores_solido.push_back({0,0,0.5}) ;
    colores_puntos.push_back({0.49,0.49,0}) ;
    colores_linea.push_back({0,0,0}) ;
  }
   color_impar_ajedrez = {0,0,0.5} ;
   color_par_ajedrez = {0,0,0} ;
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
    crearMalla(archivo,num_instancias,tapa_sup,tapa_inf) ;
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias, bool tapa_sup, bool tapa_inf) {
   std::vector<Tupla3f> despolarizado ;
   std::vector<Tupla3f> polos ;
   for (int i = 0 ; i < perfil_original.size() - 2 ; i++){
      despolarizado.push_back(perfil_original[i]) ;
   }
   crearTablaVertices(despolarizado,num_instancias) ;
   crearTablaTriangulos(despolarizado,num_instancias) ;
   if (tapa_inf) crearTapaInferior(perfil_original, num_instancias) ;
   if (tapa_sup) crearTapaSuperior(perfil_original, num_instancias) ;
}

void ObjRevolucion::crearTablaVertices(std::vector<Tupla3f> perfil_original, int num_instancias){
   v.clear() ;
   for (unsigned i = 0 ; i < num_instancias ; i++){
      for (unsigned j = 0 ; j < perfil_original.size()  ; j++){
         Tupla3f instancia_perfil_rotado = Rotacion(/*Añadir eje,*/ perfil_original[j],i,num_instancias) ;
         v.push_back(instancia_perfil_rotado) ;
      }
   }
}

void ObjRevolucion::crearTablaTriangulos(std::vector<Tupla3f> perfil_original, int num_instancias){
   f.clear() ;
   for (unsigned i = 0 ; i < num_instancias ; i++){
      for (unsigned j = 0 ; j < perfil_original.size() - 1 ; j++){
         float a = perfil_original.size() * i + j ;
         float b = perfil_original.size() * ((i+1) % num_instancias) + j ;
         f.push_back({a,b,b+1}) ;
         f.push_back({a,b+1,a+1}) ;
      }
   }
}

Tupla3f ObjRevolucion::Rotacion(Tupla3f vertice, unsigned instancia, unsigned num_instancias){
   /*De momento rotará con el eje Y*/
	Tupla3f rotado ;
	float x, y, z;
	float angulo = ((2 * PI * instancia) / num_instancias);

	y = vertice[1];
	x = ((cos(angulo) * vertice[0]) + (vertice[2] * sin(angulo)));
	z = ((-sin(angulo) * vertice[0]) + (vertice[2] * cos(angulo)));

	rotado = {x,y,z} ;

	return rotado;
}

void ObjRevolucion::crearTapaInferior(std::vector<Tupla3f> perfil_original, int num_instancias){
   std::vector<Tupla3f> despolarizado, polos ;
   for (int i = 0 ; i < perfil_original.size() - 2 ; i++){
      despolarizado.push_back(perfil_original[i]) ;
   }
   for (int i = perfil_original.size() - 2 ; i < perfil_original.size() ; i++){
      polos.push_back(perfil_original[i]) ;
   }
   v.push_back(polos[0]) ;
         int tam = v.size() ;
   for (int i = 0 ; i < num_instancias; i++ ){
         f.push_back({ v.size() - 1 ,((i+2)*despolarizado.size() % (v.size()-1)) ,((i+1)*despolarizado.size() % (v.size()-1))});
   }
}

void ObjRevolucion::crearTapaSuperior(std::vector<Tupla3f> perfil_original, int num_instancias){
   std::vector<Tupla3f> despolarizado, polos ;
   for (int i = 0 ; i < perfil_original.size() - 2 ; i++){
      despolarizado.push_back(perfil_original[i]) ;
   }
   for (int i = perfil_original.size() - 2 ; i < perfil_original.size() ; i++){
      polos.push_back(perfil_original[i]) ;
   }
   v.push_back(polos[1]) ;
         int tam = v.size() ;
   for (int i = 0 ; i < num_instancias; i++ ){
         f.push_back({ v.size() - 1 ,(((i+1)*despolarizado.size()-1) % (v.size()-2)) ,(((i+2)*despolarizado.size()-1) % (v.size()-2))});
   }
}
