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
#include "jerarquico.h"
#include "cuadro.h"
#include "luz.h"
#include "luzdireccional.h"
#include "luzposicional.h"
#include "aux.h"
#include "materiales.h"
#include "camara.h"

typedef enum {OUTV, PUNTOS, LINEAS, COLOR, AJEDREZ, ILUMINACION, JERARQUICOMAN, JERARQUICOAUTO, SELCAMARA} submenu_visual ;
typedef enum {OFF,LUZ0,LUZ1, LUZ2} submenu_iluminacion ;
typedef enum {OUTO, TETRAEDRO, CUBO, PLY} submenu_objeto ;
typedef enum {OUTD, INMEDIATO, DIFERIDO, PLANO, SUAVE} submenu_dibujo ;
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
   int modoDib; //Ve qué modo de dibujado hace
   int modo ;
   ObjPLY * ply = nullptr ;
   ObjPLY * ply2 = nullptr ;
   ObjPLY * banco = nullptr ;
   ObjRevolucion * peondif = nullptr ;
   ObjRevolucion * peonesp = nullptr ;
   Cono * cono = nullptr ;
   Cilindro * cilindro = nullptr ;
   Esfera * esfera = nullptr ;
   Ganso * ganso = nullptr ;
   Cuadro * cuadro = nullptr ;
   Cuadro * ajedrez = nullptr ;
   Cuadro * skybox1 = nullptr ;
   Cuadro * skybox2 = nullptr ;
   Cuadro * skybox3 = nullptr ;
   Cuadro * skybox4 = nullptr ;
   Cuadro * cielo = nullptr ;
   Luz * luz = nullptr ;
   LuzDireccional * luzdir = nullptr ;
   LuzPosicional * luzpos = nullptr ;
   LuzPosicional * luzpos2 = nullptr ;

   int veces_sup = 0, veces_inf = 0 ;
   float animacion = 1.0 ;
   bool angulo = false ;
   bool teclamodo = false ;
   bool orientacion = false ;
   bool shaders = true ;
   bool pausa = true ;
   bool botonIzquierdo = false ;
   bool seleccion = false ;

   //Vectores e índices
   std::vector<bool> modos = {false,false,false,false,false} ;
   std::vector<bool> luces = {false,false,false} ;
   std::vector<bool> grados_libertad = {false,false,false,false,false,false,false,false,false} ;

   //Cámaras
   std::vector<int> seleccion_camara = {0,0,0} ;
   int camaraActiva ;
   std::vector<Camara> camaras ;
   float x_ant, y_ant ;


   
   public:

    submenu_objeto subObjeto;
    submenu_dibujo subDibujo;
    submenu_visual subVisual;
    submenu_iluminacion subIlum ;

    Escena();
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
    void clickRaton(int boton, int estado, int x, int y) ;
    void ratonMovido(int x, int y) ;
    int procesarClick(int x, int y) ;
    void ratonPasado(int x, int y) ;
    void dibujarSeleccion() ;

    //Practica 4- Animacion automatica
    void animarModeloJerarquico() ;

};
#endif
