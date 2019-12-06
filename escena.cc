

#include "aux.h"     // includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************

Escena::Escena()
{
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
    // .......completar: ...
    // .....

    cubo = new Cubo(100) ;
    tetraedro = new Tetraedro(100) ;
    ply = new ObjPLY("plys/ant.ply") ;
    cilindro = new Cilindro(1,20,70,40) ;
    peonesp = new ObjRevolucion("plys/peon_inverso.ply",20,true,true) ;
    peondif = new ObjRevolucion("plys/peon.ply",20,true,true) ;
    cono = new Cono(1, 20, 70, 40) ;
    esfera = new Esfera(50,50,40) ;
    luzdir = new LuzDireccional({0.0,30.0},GL_LIGHT1,{1.0,1.0,1.0,0.0},{0.0,0.0,0.0,0.0},{1.0,1.0,1.0,0.0}) ;
    luzpos = new LuzPosicional({30.0,0.0,0.0},GL_LIGHT2,{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0}) ;
    modoDib = false ;
    modo = 2;
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height )
{
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

   change_projection( float(UI_window_width)/float(UI_window_height) );
	glViewport( 0, 0, UI_window_width, UI_window_height );
}



// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes,
// y dibuja los objetos
//
// **************************************************************************

void Escena::dibujar()
{
   glDisable (GL_LIGHTING) ;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE) ;
   glEnable(GL_CULL_FACE);
   glEnableClientState(GL_COLOR_ARRAY) ;
    ejes.draw();

    switch(subDibujo){
      if (glIsEnabled(GL_LIGHTING)){
         case SUAVE : modoDib = true ; break ;
         case PLANO : modoDib = false ; break ;
       }
       else{
          case INMEDIATO: modoDib = true ; break ;
          case DIFERIDO : modoDib = false; break ;
       }
    }

  switch(subVisual){
         
         case PUNTOS: modo = 0 ; subVisual = OUTV ; break;
         case LINEAS: modo = 1 ; subVisual = OUTV ; break;
         case COLOR: modo = 2; subVisual = OUTV ; break;
         case AJEDREZ: modo = 3; subVisual = OUTV ;  break;
         case ILUMINACION: modo = 4 ; break;
    }

      if (!teclamodo) modo = -4 ;
      glEnable (GL_NORMALIZE) ;
      peondif -> setMaterial(new MaterialUltraDifuso()) ;
      peonesp -> setMaterial(new MaterialUltraEspecular()) ;
      /*Las luces son al final objetos que se ponen en la escena,
      por lo que se pueden tratarse como si fueran figuras*/
      glPushMatrix() ;
         if(luces[0]) luzdir->activar() ;
         else luzdir->desactivar() ;
      glPopMatrix() ;
         if(luces[1]) luzpos->activar() ;
         else luzpos->desactivar() ;
      glPushMatrix() ;
      glPopMatrix() ;
      glPushMatrix();
         glTranslatef(0,0,-100);
         glTranslatef(0,10,0);
         esfera->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(0,0,100);
         glTranslatef(0,10,0);
         tetraedro->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(-100,0,0);
         cubo->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(100,0,0);
         cono->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(0,10,0);
         cilindro->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(100,10,-100);
         ply->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(-100,10,100);
         glScalef(30,30,30);
         peonesp->draw(modo, modoDib) ;
      glPopMatrix();
      glPushMatrix();
         glTranslatef(-100,10,-100);
         glScalef(30,30,30);
         peondif->draw(modo, modoDib) ;
      glPopMatrix();
      glDisable(GL_NORMALIZE) ;
      modo =-4 ;
    
    
    // COMPLETAR
    //   Dibujar los diferentes elementos de la escena
    // Habrá que tener en esta primera práctica una variable que indique qué objeto se ha de visualizar
    // y hacer 
    // cubo.draw()
    // o
    // tetraedro.draw()
   
    
}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y )
{
   using namespace std ;
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   bool salir=false;
   teclamodo = false ;
  
   switch( toupper(tecla) )
   {
      case 'Q' :
         if (modoMenu!=NADA){
            teclamodo = false ;
           
            modoMenu=NADA; 
            cout << "Volviendo a menú principal" << endl ;    
         }      
         else {
            cout << "Saliendo del programa..." << endl ;
            salir=true ;
         }
         break ;
      case 'O' :
         // ESTAMOS EN MODO SELECCION DE OBJETO
         cout << "Seleccionando objeto" << endl ;
         modoMenu=SELOBJETO; 
         break ;
        case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
         cout << "Seleccionando visualización" << endl ;
         modoMenu=SELVISUALIZACION;
         break ;
       case 'D' :
         // ESTAMOS EN MODO SELECCION DE DIBUJADO
         cout << "Seleccionando dibujado" << endl ;
         modoMenu=SELDIBUJADO;
         break ;
         // COMPLETAR con los diferentes opciones de teclado
         case 'N' :
         if (modoMenu == NADA){
            cout << "Tapa superior" << endl ;
            veces_sup++ ;
            peondif->modificarTapas(veces_sup%2 == 0,veces_inf%2 == 0) ;
         }
         break ;
         case 'M' :
         if (modoMenu == NADA){
            cout << "Tapa inferior" << endl ;
            veces_inf++ ;
            peondif->modificarTapas(veces_sup%2 == 0, veces_inf%2 == 0) ;
         }
         break ;
   }

   if (modoMenu == SELOBJETO){
      teclamodo = false ;
     
      switch (toupper(tecla)){
         case 'C'://Ver cubo
            cout << "Activado/desactivado : cubo" << endl ;
            subObjeto=CUBO ;
         break;
         case 'T'://Ver tetraedro
            cout << "Activado/desactivado : tetraedro" << endl ;
            subObjeto=TETRAEDRO ;
         break;
         case 'P':
            cout << "Activado/desactivado : malla PLY" << endl ;
            subObjeto=PLY;
         break;
      }
   }

   if (modoMenu == SELVISUALIZACION){
      teclamodo = true ;
     
      switch (toupper(tecla)){
         case 'P':
            cout << "Activado/desactivado : modo puntos" << endl ;
            glPolygonMode(GL_FRONT_AND_BACK,GL_POINT); 
            subVisual=PUNTOS ;
         break;
         case 'L':
            cout << "Activado/desactivado : modo líneas" << endl ;
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 
            subVisual=LINEAS ;
         break;
         case 'S':
            cout << "Activado/desactivado : modo sólido" << endl ;
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); 
            subVisual=COLOR ;
         break;
         case 'A':
            if (subIlum != LUZ0){
            cout << "Activado/desactivado : modo ajedrez" << endl ;
            subVisual=AJEDREZ ;
            }
         break;
         case 'I':
           
            cout << "Activado/desactivado : Iluminacion" << endl ;
            subVisual=ILUMINACION;
         break;
      }

      if (subVisual == ILUMINACION){
         switch (toupper(tecla)){
            case '0':
               teclamodo = false ;
               subIlum = LUZ0 ;
               cout << "Activado/desactivado : Luz Direccional" << teclaluz << endl ;
               luces[0] = !luces[0] ;
            break ;
            case '1':
               teclamodo = false ;
               subIlum = LUZ1 ;
               cout << "Activado/desactivado : Luz Posicional" << endl ;
               luces[1] = !luces[1] ;
            break;
         }
      }

      if (glIsEnabled(GL_LIGHT1)){
         teclamodo = false ;
        
         if (toupper(tecla) == 'A') angulo = false;
         if (toupper(tecla) == 'B') angulo = true ;
         if (tecla == '<') angulo? luzdir->variarAnguloBeta(-1.0) : luzdir->variarAnguloAlfa(-1.0) ;
         if (tecla == '>') angulo? luzdir->variarAnguloBeta(1.0) : luzdir->variarAnguloAlfa(1.0) ;
      }
   }

   if(modoMenu == SELDIBUJADO){ 
      teclamodo = false ;
     
      switch (toupper(tecla)){
         case '1':
            if(glIsEnabled(GL_LIGHTING) == false){
               cout << "Activado/desactivado : Modo inmediato" << endl ;
               subDibujo =INMEDIATO ;
            }
            else
            {
               cout << "Activado/desactivado : Iluminacion suave" << endl ;
               subDibujo =SUAVE ;
            }
         break;
         case '2':
            if(glIsEnabled(GL_LIGHTING) == false){
               cout << "Activado/desactivado : Modo diferido" << endl ;
               subDibujo =DIFERIDO ;
            }
            else
            {
               cout << "Activado/desactivado : Iluminacion plana" << endl ;
               subDibujo =PLANO ;
            }
         break;
      }
   }

   glutPostRedisplay();
   return salir;
}
//**************************************************************************

void Escena::teclaEspecial( int Tecla1, int x, int y )
{
   teclamodo = false ;
  
   switch ( Tecla1 )
   {
	   case GLUT_KEY_LEFT:
         Observer_angle_y-- ;
         break;
	   case GLUT_KEY_RIGHT:
         Observer_angle_y++ ;
         break;
	   case GLUT_KEY_UP:
         Observer_angle_x-- ;
         break;
	   case GLUT_KEY_DOWN:
         Observer_angle_x++ ;
         break;
	   case GLUT_KEY_PAGE_UP:
         Observer_distance *=1.2 ;
         break;
	   case GLUT_KEY_PAGE_DOWN:
         Observer_distance /= 1.2 ;
         break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection( const float ratio_xy )
{
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();
   const float wx = float(Height)*ratio_xy ;
   glFrustum( -Width, Width, -Height, Height, Front_plane, Back_plane );
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight )
{
   Width  = newWidth/10;
   Height = newHeight/10;
   change_projection( float(newHeight)/float(newWidth) );
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer()
{
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef( 0.0, 0.0, -Observer_distance );
   glRotatef( Observer_angle_y, 0.0 ,1.0, 0.0 );
   glRotatef( Observer_angle_x, 1.0, 0.0, 0.0 );
}
