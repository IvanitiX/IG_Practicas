#include "textura.h"

Textura::Textura(std::string file){
    jpg::Imagen * imagen = nullptr ;
    if(imagen == nullptr) imagen = new jpg::Imagen(file) ;
    width = imagen -> tamX() ;
    height = imagen -> tamY() ;
    data = imagen -> leerPixels() ;
    glGenTextures(1, &idTex) ;
    glBindTexture(GL_TEXTURE_2D,idTex) ;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void Textura::activar(){
    gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, width, height,
                    GL_RGB, GL_UNSIGNED_BYTE, &data[0]) ;
}

