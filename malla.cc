#include "aux.h"
#include "malla.h"

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

void Malla3D::drawAjedrez(){
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
      for (int i = 0; i < v.size(); i++){
		   color_impar.push_back(color_impar_ajedrez);
		   color_par.push_back(color_par_ajedrez);
	   }

      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

      glEnableClientState(GL_VERTEX_ARRAY) ;
         glVertexPointer (3,GL_FLOAT,0,v.data());

         glEnableClientState(GL_COLOR_ARRAY) ;
            glColorPointer(3,GL_FLOAT,0,color_par.data()) ;
            glDrawElements(GL_TRIANGLES,caras_pares.size()*3,GL_UNSIGNED_INT,caras_pares.data()) ;

            glColorPointer(3,GL_FLOAT,0,color_impar.data()) ;
            glDrawElements(GL_TRIANGLES,caras_impares.size()*3,GL_UNSIGNED_INT,caras_impares.data()) ;
         glDisableClientState(GL_COLOR_ARRAY) ;

      glDisableClientState(GL_VERTEX_ARRAY) ;
}


// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(std::vector<bool> modos)
{
   if (modos[0]||modos[1]||modos[2]){
      glEnableClientState(GL_VERTEX_ARRAY);
      glEnableClientState(GL_COLOR_ARRAY);
      glVertexPointer( 3,GL_FLOAT, 0, v.data() ) ;
      glShadeModel(GL_FLAT);

      if(modos[4]){
         glDisable(GL_LIGHTING) ;
         modos[4] = false ;
      }

      if(modos[0]){
         glColorPointer(3,GL_FLOAT,0,colores_puntos.data()) ;
         glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
         glPointSize(4);
         glDrawElements(GL_TRIANGLES, f.size() * 3, GL_UNSIGNED_INT, f.data());
      }

      if(modos[1]){
         glColorPointer(3,GL_FLOAT,0,colores_linea.data()) ;
         glLineWidth(2) ;
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         glDrawElements(GL_TRIANGLES, f.size() * 3, GL_UNSIGNED_INT, f.data());
      }

      if(modos[2]){
         glColorPointer(3,GL_FLOAT,0,colores_solido.data()) ;
         glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
         glDrawElements(GL_TRIANGLES, f.size() * 3, GL_UNSIGNED_INT, f.data());
      }

      glDisableClientState(GL_COLOR_ARRAY) ;
      glDisableClientState(GL_VERTEX_ARRAY);
   }

   if(modos[4]){
		material -> aplicar();

		if(normales.size()==0) calcular_normales();
		
		glEnable(GL_NORMALIZE);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);

      glNormalPointer(GL_FLOAT, 0, normales.data());
		glVertexPointer(3, GL_FLOAT, 0, v.data());

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawElements(GL_TRIANGLES, f.size() * 3, GL_UNSIGNED_INT, f.data());

		glDisableClientState(GL_NORMAL_ARRAY);
      glDisableClientState(GL_VERTEX_ARRAY);
	}
   
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

void Malla3D::draw_ModoDiferido(std::vector<bool> modos)
{
   // (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   // completar (práctica 1)
   // .....
   if (id_vbo_ver == 0)
      id_vbo_ver = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float),v.data()) ;
   if (id_vbo_tri == 0)
      id_vbo_tri = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 3*f.size()*sizeof(unsigned int),f.data()) ;
   if (id_vbo_normales == 0){
      if(normales.size() == 0) calcular_normales() ;
      id_vbo_normales = CrearVBO(GL_ARRAY_BUFFER, 3*normales.size()*sizeof(float),normales.data()) ;
   }
   if (id_vbo_color == 0)
      id_vbo_color = CrearVBO(GL_ARRAY_BUFFER, 3*colores_solido.size()*sizeof(float), colores_solido.data()) ;
      

   glBindBuffer(GL_ARRAY_BUFFER, id_vbo_ver);
   glVertexPointer(3,GL_FLOAT,0,0);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glEnableClientState(GL_VERTEX_ARRAY);

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id_vbo_tri);

   if(modos[0] || modos[1] || modos[2]){

      if(modos[4]){
         glDisable(GL_LIGHTING) ;
         modos[4] = false ;
      }

      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_color);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
      glEnableClientState(GL_COLOR_ARRAY);

      if(modos[0]){
         glPointSize(4) ;
          glColorPointer(3, GL_FLOAT, 0, colores_puntos.data());
          glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
          glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
      }
      if(modos[1]){
          glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
          glColorPointer(3, GL_FLOAT, 0, colores_linea.data());
          glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
          glLineWidth(2) ;
      }
      if(modos[2]) {
         glColorPointer(3, GL_FLOAT, 0, colores_solido.data());
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
         glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
      }

      
      glDisableClientState(GL_COLOR_ARRAY) ;
   }

   if(modos[4]){
      material -> aplicar() ;

      glEnable(GL_NORMALIZE) ;
      glBindBuffer(GL_ARRAY_BUFFER, id_vbo_normales);
		glNormalPointer(GL_FLOAT, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnableClientState(GL_NORMAL_ARRAY);
		glDrawElements(GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0);
      glDisable(GL_NORMALIZE) ;
		glDisableClientState(GL_NORMAL_ARRAY) ;
   }


   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
   glDisableClientState(GL_VERTEX_ARRAY);
}

// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(){
   glEnableClientState(GL_VERTEX_ARRAY) ;
   glEnableClientState(GL_COLOR_ARRAY) ;
   glVertexPointer( 3,GL_FLOAT, 0, v.data() ) ;
   glColorPointer(3, GL_FLOAT, 0, colores.data());
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL) ;
   glDrawElements(GL_TRIANGLES,f.size()*3,GL_UNSIGNED_INT, f.data()) ;
   glDisableClientState(GL_COLOR_ARRAY) ;
   glDisableClientState(GL_VERTEX_ARRAY) ;
}

void Malla3D::draw(int modo_dibujado , std::vector<bool> modos)
{
   if(colores_linea.empty()){
      for (int i = 0 ; i < v.size() ; i++){
         colores.push_back(solido) ;
         colores_puntos.push_back(puntos) ;
         colores_linea.push_back(linea) ;
         colores_solido.push_back(solido) ;
      }
   }

   if (textura != nullptr && ct.size() > 0){
         glEnable(GL_TEXTURE_2D) ;
         glEnableClientState(GL_TEXTURE_COORD_ARRAY_EXT) ;
         glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
         textura -> activar() ;
   } 

   if(modos[3] && (modo_dibujado == 1 || modo_dibujado == 2))
      drawAjedrez() ;

   else switch (modo_dibujado){
      case 1:
         draw_ModoInmediato(modos) ;
      break ;
      case 2:
         draw_ModoDiferido(modos) ;
      break ;
   }

   if(textura != nullptr && ct.size() > 0){
      glDisableClientState(GL_TEXTURE_COORD_ARRAY_EXT) ;
      glDisable(GL_TEXTURE_2D) ;
   }
}


GLuint Malla3D::CrearVBO (GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram){
   GLuint id_vbo ;
   glGenBuffers (1, &id_vbo) ;
   glBindBuffer (tipo_vbo, id_vbo) ;
   glBufferData (tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW) ;
   glBindBuffer(tipo_vbo, 0) ;
   return id_vbo ;
}

void Malla3D::calcular_normales(){
   std::vector<Tupla3f> normales_cara ;
   //Primera parte: normales de caras
   for (unsigned i = 0 ; i < f.size() ; i++){
      Tupla3i cara = f[i] ;
      Tupla3f a = {v[cara[2]]-v[cara[1]]} ;
      Tupla3f b = {v[cara[1]]-v[cara[0]]} ;
      Tupla3f res = a.cross(b) ;
      float x = res[0] ;
      float y = res[1];
      float z = res[2];
      float modulo = sqrt(x*x+y*y+z*z) ;
      Tupla3f p_vec = {x/modulo,y/modulo,z/modulo} ;
      normales_cara.push_back(p_vec/modulo) ;
   }
   //Segunda parte: normales de vértices
   //2.1 Poner las normales de vértices a 0
   for (unsigned i = 0 ; i < v.size() ; i++){
      normales.push_back({0,0,0}) ;
   }
   //2.2 Ir añadiendo las normales según las caras.
   for (unsigned i = 0 ; i < f.size() ; i++){
      Tupla3i vertices_cara = f[i] ;
      normales[vertices_cara[0]] = (normales[vertices_cara[0]] + normales_cara[i]);
      normales[vertices_cara[1]] = (normales[vertices_cara[1]] + normales_cara[i]);
      normales[vertices_cara[2]] = (normales[vertices_cara[2]] + normales_cara[i]);
   }

   for (unsigned i = 0 ; i < v.size() ; i++){
      Tupla3f input = normales[i] ;
      float x = input[0] ;
      float y = input[1] ;
      float z = input[2] ;
      float modulo = sqrt(x*x+y*y+z*z) ;
      normales[i] = {x/modulo,y/modulo,z/modulo} ;
   }
}

   void Malla3D::setMaterial(Material * mat){
      *material = *mat ;
   }

   void Malla3D::setColorSolido(Tupla3f color){
      colores_solido.clear() ;
      for (int i = 0 ; i < v.size() ; i++)
         colores_solido.push_back(color) ;
   }

   void Malla3D::setColorInvisible(Tupla3f color){
      colores.clear() ;
      for (int i = 0 ; i < v.size() ; i++)
         colores.push_back(color) ;
   }

   void Malla3D::setTextura(Textura * tex){
      textura = tex ;
   }

