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
#include "textura.h"

// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D
{
   public:
   void drawAjedrez() ;

   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato(std::vector<bool> modos);

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido(std::vector<bool> modos);

   // función que redibuja el objeto
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(int, std::vector<bool>) ;
   void draw() ;

   void setMaterial (Material * mat) ;
   void setColorSolido(Tupla3f color) ;
   void setTextura(Textura * tex) ;

   

   protected:

   Textura * textura = nullptr ;
   std::vector<Tupla2f> ct ;

   void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)

   std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo
   Tupla3f puntos, linea, solido ;
   std::vector<Tupla3f> colores_solido, colores_linea, colores_puntos, colores ;
   std::vector<Tupla3f> normales ;
   Tupla3f color_par_ajedrez, color_impar_ajedrez;
   Material * material = nullptr;


   GLuint CrearVBO(GLuint, GLuint, GLvoid*) ;

   GLuint id_vbo_ver = 0 , id_vbo_tri = 0, id_vbo_normales = 0 , id_vbo_color = 0 ;

   std::vector<bool> modos = {false,false,false,false,false} ;
   int ultimoModo = -1 ;



   // completar: tabla de colores, tabla de normales de vértices
} ;


#endif
