#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo )
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
   for(unsigned i = 0 ; i < v.size() ; i++){
    colores_solido.push_back({127,0,127}) ;
    colores_puntos.push_back({0,127,0}) ;
    colores_linea.push_back({0,0,0}) ;
  }
}


