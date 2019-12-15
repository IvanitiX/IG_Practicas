// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "materiales.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:
   void drawLineas(bool);
   void drawSolido(bool);
   void drawPuntos(bool);
   void drawAjedrez(bool) ;
   void drawIluminacion(bool) ;

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato();

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido();

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int, bool) ;

   void setMaterial (Material * mat) ;
   void setColorSolido(Tupla3f color) ;

   

   protected:

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   std::vector<Tupla3f> colores_solido, colores_linea, colores_puntos ;
   std::vector<Tupla3f> normales ;
   Tupla3f color_par_ajedrez, color_impar_ajedrez;
   Material * material = nullptr;


   GLuint CrearVBO(GLuint, GLuint, GLvoid*) ;

   GLuint id_vbo_ver = 0 , id_vbo_tri = 0 ;

   std::vector<bool> modos = {false,false,false,false,false} ;
   int ultimoModo = -1 ;



   // completar: tabla de colores, tabla de normales de vértices
} ;


#endif
