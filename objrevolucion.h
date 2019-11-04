// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cubo.h

//
// #############################################################################

#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "ply_reader.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
   public:
       ObjRevolucion();
       ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=false, bool tapa_inf=false) ;
       ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=false, bool tapa_inf=false) ;
       void detectarTapas(std::vector<Tupla3f>) ;
       void modificarTapas(bool, bool) ;
   protected:
       void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias, bool tapa_sup=false, bool tapa_inf=false);
       std::vector<Tupla3f> formatoPerfil(std::vector<Tupla3f> perfil_original) ;
   private:
       void crearTablaVertices(std::vector<Tupla3f> perfil_original, int num_instancias) ;
       void crearTablaTriangulos(std::vector<Tupla3f> perfil_original, int num_instancias) ;
       Tupla3f Rotacion(/*char eje,*/Tupla3f vertice, unsigned instancia, unsigned num_instancias) ;
       void crearTapaSuperior(std::vector<Tupla3f> perfil_original, int num_instancias);
       void crearTapaInferior(std::vector<Tupla3f> perfil_original, int num_instancias);

      /*Variables*/
       bool extremos[2] ;
       const float PI = 3.1415926535897932384 ;
       std::vector<Tupla3f> perfil_asociado ;
       int instancias = 0 ;
} ;




#endif
