#include "material.h"

Material::Material(Tupla4f mdifuso, Tupla4f mespecular, Tupla4f mambiente, float brillo){
    colorMatDifuso = mdifuso ;
    especular = mespecular ;
    ambiente = mambiente ;
    brillo = brillo;
}

void Material::aplicar(){
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambiente) ;
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, colorMatDifuso) ;
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, especular) ;
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, brillo) ;
}

