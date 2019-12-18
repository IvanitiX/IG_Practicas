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

  solido = {0.5,0,0.5} ;
  puntos = {0,0.5,0} ;
  linea = {0,0,0} ;

  color_impar_ajedrez = {0.5,0,0.5} ;
  color_par_ajedrez = {0,0,0} ;

  MaterialCian * mc = new MaterialCian() ;
  material = mc ;
}


