#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "objply.h"
#include "objrevolucion.h"
#include "cono.h"
#include "cilindro.h"
#include "esfera.h"

typedef enum {OUTV, PUNTOS, LINEAS, COLOR, AJEDREZ} submenu_visual ;
typedef enum {OUTO, TETRAEDRO, CUBO, PLY} submenu_objeto ;
typedef enum {OUTD, INMEDIATO, DIFERIDO} submenu_dibujo ;
typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO} menu;
class Escena
{

   private:

   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection( const float ratio_xy );
	void change_observer();
    


   void clear_window();

   menu modoMenu=NADA;

   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
   Malla3D * malla= nullptr;
   Malla3D * malla2 = nullptr ;
   bool modoDib; //Ve qué modo de dibujado hace
   int modo;
   ObjPLY * ply = nullptr ;
   ObjRevolucion * objRev = nullptr ;
   Cono * cono = nullptr ;
   Cilindro * cilindro = nullptr ;
   Esfera * esfera = nullptr ;

   
   public:

    submenu_objeto subObjeto;
    submenu_dibujo subDibujo;
    submenu_visual subVisual;

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );

};
#endif
