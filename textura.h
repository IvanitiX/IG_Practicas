#include "jpg_imagen.hpp"
#include "aux.h"

#ifndef TEXTURA
#define TEXTURA
    class Textura{
        public :
            Textura (std::string file) ;
            void activar() ;
        protected :
        GLuint idTex = 0 ;
        unsigned char * data ;
        int width,height ;
    } ;
#endif