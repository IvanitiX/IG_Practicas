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
   crearMalla(this->v,num_instancias,tapa_sup,tapa_inf);
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
    crearMalla(archivo,num_instancias,tapa_sup,tapa_inf) ;
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias, bool tapa_sup, bool tapa_inf) {
   crearTablaVertices(perfil_original,num_instancias) ;
   crearTablaTriangulos(perfil_original,num_instancias) ;
   if (tapa_inf) crearTapaInferior(perfil_original, num_instancias) ;
   if (tapa_sup) crearTapaSuperior(perfil_original, num_instancias) ;
}

void ObjRevolucion::crearTablaVertices(std::vector<Tupla3f> perfil_original, int num_instancias){
   v.clear() ;

   for (unsigned i = 0 ; i < num_instancias ; i++){
      for (unsigned j = 0 ; j < perfil_original.size() ; j++){
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
	Tupla3f * rotado = nullptr;
	float x, y, z;
	float angulo = ((2 * PI * instancia) / num_instancias);

	y = vertice[1];
	x = ((cos(angulo) * vertice[0]) + (vertice[2] * sin(angulo)));
	z = ((-sin(angulo) * vertice[0]) + (vertice[2] * cos(angulo)));

	rotado = new Tupla3f (x,y,z) ;

	return *rotado;
}

void ObjRevolucion::crearTapaInferior(std::vector<Tupla3f> perfil_original, int num_instancias){
   float y = perfil_original[0][1] ;
   v.push_back({0, y , 0});
         int tam = v.size() ;
   for (int i = 0 ; i < num_instancias; i++ ){
         f.push_back( { v.size()-1,((i+2)*perfil_original.size())%(v.size()-1),((i+1)*perfil_original.size())%(v.size()-1)} );
   }
}

void ObjRevolucion::crearTapaSuperior(std::vector<Tupla3f> perfil_original, int num_instancias){
   v.push_back({0, perfil_original[perfil_original.size()-1][1], 0});
   int tam = v.size() ;
   for (int i = 0 ; i < num_instancias-1; i++ ){
         f.push_back( { v.size()-1,((i+1)*perfil_original.size()-1)%(v.size()-1),((i+2)*perfil_original.size()-1)%(v.size()-1)} );
   }
}
