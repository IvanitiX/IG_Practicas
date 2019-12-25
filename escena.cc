

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
    cubo -> setTextura(new Textura("img/madera.jpg")) ;
    cubo -> setColorSolido({1,1,1}) ;
    cubo -> setMaterial(new MaterialNaranja()) ;
    tetraedro = new Tetraedro(100) ;
    tetraedro -> setTextura(new Textura("img/Dado.jpg")) ;
    ply = new ObjPLY("plys/ant.ply") ;
    ply2 = new ObjPLY("plys/cesta.ply") ;
    cilindro = new Cilindro(1,20,70,40) ;
    peonesp = new ObjRevolucion("plys/peon_inverso.ply",20,true,true) ;
    peonesp -> setColorSolido({0.1,0.1,0.1}) ;
    peondif = new ObjRevolucion("plys/peon.ply",20,true,true) ;
    peondif -> setColorSolido({0.9,0.9,0.9}) ;
    cono = new Cono(1, 20, 70, 40) ;
    esfera = new Esfera(50,50,40) ;
    ganso = new Ganso() ;
    cuadro = new Cuadro() ;
    cuadro -> setTextura(new Textura("img/Cemento.jpg")) ;
    skybox1 = new Cuadro() ;
    skybox1 -> setTextura(new Textura("img/Skybox1.jpg")) ;
    skybox1 -> setColorSolido({1,1,1}) ;
    skybox2 = new Cuadro();
    skybox2 -> setTextura(new Textura("img/Skybox2.jpg")) ;
    skybox2 -> setColorSolido({1,1,1}) ;
    skybox3 = new Cuadro() ;
    skybox3 -> setTextura(new Textura("img/Skybox3.jpg")) ;
    skybox3 -> setColorSolido({1,1,1}) ;
    skybox4 = new Cuadro();
    skybox4 -> setTextura(new Textura("img/Skybox4.jpg")) ;
    skybox4 -> setColorSolido({1,1,1}) ;
    cielo = new Cuadro() ;
    cielo -> setTextura(new Textura("img/Cielo.jpg")) ;
    cielo -> setColorSolido({1,1,1}) ;
    ajedrez = new Cuadro() ;
    ajedrez -> setTextura (new Textura("img/ajedrez.jpg")) ;
    ajedrez -> setColorSolido({1,1,1}) ;
    luzdir = new LuzDireccional({0.0,30.0},GL_LIGHT1,{1.0,1.0,1.0,1.0},{0.0,0.0,0.0,0.0},{1.0,1.0,1.0,0.0}) ;
    luzpos = new LuzPosicional({30.0,0.0,0.0},GL_LIGHT2,{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0},{1.0,1.0,1.0,1.0}) ;
    luzpos2 = new LuzPosicional({0.0,-45.0,0.0},GL_LIGHT3,{0.0,1.0,1.0,1.0},{0.0,1.0,1.0,1.0},{0.0,1.0,1.0,1.0}) ;
    modoDib = false ;
    modo = 2;
    modoDib = 1 ;
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
   glDisable(GL_TEXTURE_2D) ;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE) ;
   glEnable(GL_CULL_FACE);
   glEnableClientState(GL_COLOR_ARRAY) ;
    ejes.draw();

    shaders ? glShadeModel(GL_SMOOTH) : glShadeModel(GL_FLAT) ;

    switch(subDibujo){
          case INMEDIATO: modoDib = 1 ; break ;
          case DIFERIDO : modoDib = 2; break ;
       }

  switch(subVisual){
         
         case PUNTOS: modo = 0 ; modos[0] = !modos[0] ; subVisual = OUTV ; break;
         case LINEAS: modo = 1 ; modos[1] = !modos[1] ; subVisual = OUTV ; break;
         case COLOR: modo = 2; modos[2] = !modos[2] ; subVisual = OUTV ; break;
         case AJEDREZ: modo = 3; modos[3] = !modos[3] ; subVisual = OUTV ;  break;
         case ILUMINACION: 
            modo = 4 ; 
            modos[4] = !modos[4] ; 
            if(modos[4]){
               for (int i = 0 ; i < 4 ; i++)
                  modos[i] = false ;
            }
            subVisual = OUTV ;  
            break;
    }

    if(modos[4]) glEnable(GL_LIGHTING) ;

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

      glPushMatrix() ;
         if(luces[1]) luzpos->activar() ;
         else luzpos->desactivar() ;
      glPopMatrix() ;

      glPushMatrix() ;
         glScalef(0,luzpos2->getAltura(),0) ;
         if(luces[2]) luzpos2->activar() ;
         else luzpos2->desactivar() ;
      glPopMatrix() ;

      glPushMatrix();
         glTranslatef(0,0,-100);
         glTranslatef(0,-35,0);
         glScalef (0.6,0.6,0.6) ;
         esfera->draw(modoDib,modos) ;
      glPopMatrix();

      glPushMatrix();

         glTranslatef(-100,0,0);
         glTranslatef(0,-65,0);

         glPushMatrix () ;
            glScalef (0.6,0.1,0.6) ;
            cubo->draw(modoDib, modos) ;
         glPopMatrix() ;

         glPushMatrix () ;
            glTranslatef(0,6,0) ;
            glScalef (50,50,50) ;
            ajedrez->draw(modoDib, modos) ;
         glPopMatrix() ;

         glPushMatrix();
            glTranslatef(10,13,-10) ;
            glScalef (5,5,5) ;
            peonesp->draw(modoDib,modos) ;
         glPopMatrix();

         glPushMatrix();
            glTranslatef(-10,13,10) ;
            glScalef (5,5,5) ;
            peondif->draw(modoDib,modos) ;
         glPopMatrix();

         glPushMatrix();
            glTranslatef(-20,13,-20) ;
            glScalef (0.1,0.1,0.1) ;
            tetraedro->draw(modoDib,modos) ;
         glPopMatrix();

      glPopMatrix();

      glPushMatrix();
         glTranslatef(100,0,0);
         glTranslatef(0,-45,0);
         glScalef (0.6,0.6,0.6) ;
         cono->draw(modoDib,modos) ;
      glPopMatrix();

      glPushMatrix();
         glTranslatef(100,0,100);
         cilindro->draw(modoDib,modos) ;
      glPopMatrix();

      glPushMatrix();
         glTranslatef(100,10,-100);
         glTranslatef(0,-45,0);
         glScalef (0.6,0.6,0.6) ;
         ply->draw(modoDib,modos) ;
      glPopMatrix();


      glPushMatrix() ;
         glTranslatef(0,-20,0) ;
         glScalef(0.3,0.3,0.3) ;
         ganso->draw(modoDib,modos) ;
      glPopMatrix() ;

      glPushMatrix() ;
         glTranslatef(0,-70,0) ;
         glScalef(700,700,700) ;
         cuadro-> draw(modoDib,modos) ;
      glPopMatrix() ;

      glPushMatrix() ;
         glTranslatef(0,150,-350) ;
         glScalef(700,500,0) ;
         glRotatef(180,0,0,1) ;
         glRotatef(90,1,0,0) ;
         skybox1-> draw(modoDib,modos) ;
      glPopMatrix() ;


      glPushMatrix() ;
         glRotatef(-90,0,1,0) ;
         glTranslatef(0,150,350) ;
         glScalef(700,500,0) ;
         glRotatef(-90,1,0,0) ;
         skybox2-> draw(modoDib,modos) ;
      glPopMatrix() ;

      glPushMatrix() ;
         glTranslatef(0,150,350) ;
         glScalef(700,500,0) ;
         glRotatef(-90,1,0,0) ;
         skybox3-> draw(modoDib,modos) ;
      glPopMatrix() ;

      glPushMatrix() ;
         glRotatef(90,0,1,0) ;
         glTranslatef(0,150,350) ;
         glScalef(700,500,0) ;
         glRotatef(-90,1,0,0) ;
         skybox4-> draw(modoDib,modos) ;
      glPopMatrix() ;

      glPushMatrix() ;
         glTranslatef(0,400,0) ;
         glRotatef(180,1,0,0) ;
         glScalef(700,700,700) ;
         cielo-> draw(modoDib,modos) ;
      glPopMatrix() ;



      glDisable(GL_NORMALIZE) ;
    
    
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
            subVisual=PUNTOS ;
         break;
         case 'L':
            cout << "Activado/desactivado : modo líneas" << endl ;
            subVisual=LINEAS ;
         break;
         case 'S':
            cout << "Activado/desactivado : modo sólido" << endl ; 
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
         case 'M' :
            cout << "Activado/desactivado : Animacion Manual"  <<endl ;
            pausa = true ;
            subVisual = JERARQUICOMAN ;
         break ;
         case 'J' :
            cout << "Activado/desactivado : Modificacion de Animacion Automática"  <<endl ;
            pausa = false ;
            subVisual = JERARQUICOAUTO ;
         break ;
      }

      if (modos[4]){
         switch (toupper(tecla)){
            case '0':
               teclamodo = false ;
               subIlum = LUZ0 ;
               cout << "Activado/desactivado : Luz Direccional"  << endl ;
               luces[0] = !luces[0] ;
            break ;
            case '1':
               teclamodo = false ;
               subIlum = LUZ1 ;
               cout << "Activado/desactivado : Luz Posicional" << endl ;
               luces[1] = !luces[1] ;
            break;
            case '2':
               teclamodo = false ;
               subIlum = LUZ2 ;
               cout << "Activado/desactivado : Luz Posicional 2" << endl ;
               luces[2] = !luces[2] ;
            break;
         }
      }

      if (luces[0]){
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
            cout << "Activado/desactivado : Modo inmediato" << endl ;
            subDibujo =INMEDIATO ;
         break ;
         case '2':
            cout << "Activado/desactivado : Modo diferido" << endl ;
            subDibujo =DIFERIDO ;
         break;
         if(glIsEnabled(GL_LIGHTING)){
            case '3':
               cout << "Activado/desactivado : Iluminacion suave" << endl ;
               shaders = true ;
            break ;
            case '4':
               cout << "Activado/desactivado : Iluminacion plana" << endl ;
               shaders = false ;
            break ;
         }
      }
   }

   if (subVisual == JERARQUICOMAN)
   {
      teclamodo = false ;
      switch(toupper(tecla)){
         case '+' :
            if (grados_libertad[0]) ganso -> caerPetalo(10,-10) ;
            if (grados_libertad[1]) ganso -> rotarPiernaDerecha(-2) ;
            if (grados_libertad[2]) ganso -> rotarPiernaIzquierda(2) ;
            if (grados_libertad[3]) ganso -> rotarCabeza(2,0,0) ;
            if (grados_libertad[4]) ganso -> rotarCabeza(0,2,0) ;
            if (grados_libertad[5]) ganso -> rotarCabeza(0,0,2) ;
            if (grados_libertad[6]) ganso -> rotarCuello(2,0) ;
            if (grados_libertad[7]) ganso -> rotarCuello(0,2) ;
            if (grados_libertad[8]) luzpos2 -> translacion(10) ;
         break ;
         case '-' :
            if (grados_libertad[0]) ganso -> caerPetalo(-10,10) ;
            if (grados_libertad[1]) ganso -> rotarPiernaDerecha(2) ;
            if (grados_libertad[2]) ganso -> rotarPiernaIzquierda(-2) ;
            if (grados_libertad[3]) ganso -> rotarCabeza(-2,0,0) ;
            if (grados_libertad[4]) ganso -> rotarCabeza(0,-2,0) ;
            if (grados_libertad[5]) ganso -> rotarCabeza(0,0,-2) ;
            if (grados_libertad[6]) ganso -> rotarCuello(-2,0) ;
            if (grados_libertad[7]) ganso -> rotarCuello(0,-2) ;
            if (grados_libertad[8]) luzpos2 -> translacion(-10) ;
         break ;
         case '0' :/*PetaloXY*/
            grados_libertad[0] = !grados_libertad[0] ;
         break ;
         case '1' :/*Alfa*/
            grados_libertad[1] = !grados_libertad[1] ;
         break ;
         case '2' :/*Omega*/
            grados_libertad[2] = !grados_libertad[2] ;
         break ;
         case '3' :/*Beta*/
            grados_libertad[3] = !grados_libertad[3] ;
         break ;
         case '4' :/*Gamma*/
            grados_libertad[4] = !grados_libertad[4] ;
         break ;
         case '5' :/*Delta*/
            grados_libertad[5] = !grados_libertad[5] ;
         break ;
         case '6' :/*Epsilon*/
            grados_libertad[6] = !grados_libertad[6] ;
         break ;
         case '7' :/*Chi*/
            grados_libertad[7] = !grados_libertad[7] ;
         break ;
         case '8' : /*Luz Posicional 2*/
            grados_libertad[8] = !grados_libertad[8] ;
         break ;
      }
   }

   if (subVisual == JERARQUICOAUTO)
   {
      teclamodo = false ;
      switch(toupper(tecla)){
         case '+' :
            animacion += 0.1 ;
         break ;
         case '-' :
            if (animacion > 0.1)
               animacion -= 0.1 ;
            else
               std::cout <<"Si seguimos hacia atrás, el movimiento sería caótico. Queda en pausa." << std::endl ;
         break ;
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

void Escena::animarModeloJerarquico(){
   teclamodo = false ;
   if (!pausa){
      ganso -> caerPetalo(animacion,-animacion) ;
      ganso -> rotarPiernaDerecha(animacion) ;
      ganso -> rotarPiernaIzquierda(animacion) ;
      ganso -> rotarCabeza(animacion,animacion,animacion) ;
      ganso -> rotarCuello(animacion,animacion) ;
      luzpos2 -> translacion(animacion) ; 
   }  
}
