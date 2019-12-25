#include "textura.h"

Textura::Textura(std::string file){
    jpg::Imagen * imagen = nullptr ;
    if(imagen == nullptr) imagen = new jpg::Imagen(file) ;
    width = imagen -> tamX() ;
    height = imagen -> tamY() ;
    data = imagen -> leerPixels() ;
    glGenTextures(1, &idTex) ;
    glBindTexture(GL_TEXTURE_2D,idTex) ;
}

void Textura::activar(){
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height,
                    GL_RGB, GL_UNSIGNED_BYTE, &data[0]) ;
}

