#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

void Malla3D::drawLineas(bool modoDibujado){
      glEnable(GL_COLOR_ARRAY) ;
      glColorPointer(3,GL_FLOAT,0,colores_linea.data()) ;
      glLineWidth(2) ;
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      if(modoDibujado){
         draw_ModoInmediato();
      }
      else{
         draw_ModoDiferido();
      }
}

void Malla3D::drawSolido(bool modoDibujado){
      glEnable(GL_COLOR_ARRAY) ;
      glColorPointer(3,GL_FLOAT,0,colores_solido.data()) ;
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      if(modoDibujado){
         draw_ModoInmediato();
      }
      else{
         draw_ModoDiferido();
      }
}

void Malla3D::drawPuntos(bool modoDibujado){
      glEnable(GL_COLOR_ARRAY) ;
      glColorPointer(3,GL_FLOAT,0,colores_puntos.data()) ;
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glPointSize(4);
      if(modoDibujado){
         draw_ModoInmediato();
      }
      else{
         draw_ModoDiferido();
      }
}

void Malla3D::drawAjedrez(bool modoDibujado){
      std::vector<Tupla3i> caras_pares ;
      std::vector<Tupla3i> caras_impares ;
      std::vector<Tupla3f> color_impar, color_par;

      for(int cara = 0 ; cara < f.size() ; cara++){
         if (cara%2==0){
            caras_pares.push_back(f[cara]) ;
         }
         else{
            caras_impares.push_back(f[cara]) ;
         }
      }
               int breakpoint = 0 ;
      for (int i = 0; i < v.size(); i++){
		   color_impar.push_back(color_impar_ajedrez);
		   color_par.push_back(color_par_ajedrez);
	   }

      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glShadeModel(GL_FLAT) ;

      glEnableClientState(GL_VERTEX_ARRAY) ;
         glVertexPointer (3,GL_FLOAT,0,v.data());

         glEnableClientState(GL_COLOR_ARRAY) ;
            glColorPointer(3,GL_FLOAT,0,color_par.data()) ;
            glDrawElements(GL_TRIANGLES,caras_pares.size()*3,GL_UNSIGNED_INT,caras_pares.data()) ;

            glColorPointer(3,GL_FLOAT,0,color_impar.data()) ;
            glDrawElements(GL_TRIANGLES,caras_impares.size()*3,GL_UNSIGNED_INT,caras_impares.data()) ;
         glDisableClientState(GL_COLOR_ARRAY) ;

      glDisableClientState(GL_VERTEX_ARRAY) ;

      if(modoDibujado){
         draw_ModoInmediato();
      }
      else{
         draw_ModoDiferido();
      }
}


// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato()
{
   //habilitar uso de un array de vértices
   glEnableClientState(GL_VERTEX_ARRAY);
   //  indicar el formato y la dirección de memoria del array de vértices
   //  (son tuplas de 3 valoresfloat, sin espacio entre ellas)
   glVertexPointer( 3,GL_FLOAT, 0, v.data() ) ;
   //  visualizar, indicando: tipo de primitiva, número de índices,
   //  tipo de los índices, y dirección de la tabla de índices
   glDrawElements(GL_TRIANGLES,f.size()*3,GL_UNSIGNED_INT,f.data() );
   //  deshabilitar array de vértices
   glDisableClientState(GL_VERTEX_ARRAY);

}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido()
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   if (id_vbo_ver == 0)
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float),v.data()) ;
   if (id_vbo_tri == 0)
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 3*f.size()*sizeof(unsigned int),f.data()) ;
   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3,GL_FLOAT,0,0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glEnableClientState(GL_VERTEX_ARRAY);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id_vbo_tri);
   glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

   glDisableClientState(GL_VERTEX_ARRAY);
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(int modo, bool modoDibujado)
{
   // completar .....(práctica 1)
   for(int i=0 ; i < modos.size() && ultimoModo != modo ; i++){
      if (i == modo){
         modos[i] = !modos[i] ;
      }
   }
   ultimoModo = modo ;

   if(modos[0] == true) drawPuntos(modoDibujado) ;
   if(modos[1] == true) drawLineas(modoDibujado) ;
   if(modos[2] == true) drawSolido(modoDibujado) ;
   if(modos[3] == true) drawAjedrez(modoDibujado) ;
   
}


GLuint Malla3D::CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){
   GLuint id_vbo ;
   glGenBuffers (1, &id_vbo) ;
   glBindBuffer (tipo_vbo, id_vbo) ;
   glBufferData (tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW) ;
   glBindBuffer(tipo_vbo, 0) ;
   return id_vbo ;
}

