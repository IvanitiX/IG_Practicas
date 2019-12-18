#include "jerarquico.h"

/*Constructores de partes jerárquicas*/
Petalo::Petalo(){
    petEsfera = new Esfera(40,40,20.0) ;
}

Tulipa::Tulipa(){
    caidaPetaloX = 0 ;
    caidaPetaloY = 0 ;
    tulPetaloAbajo = new Petalo() ;
    tulPetaloAbajo -> setColorPetalo({1,0,0}) ; //Rojo
    tulPetaloArriba = new Petalo() ;
    tulPetaloArriba -> setColorPetalo({0,1,0}) ; //Verde
    tulPetaloDer = new Petalo() ;
    tulPetaloDer -> setColorPetalo({0,0,1}) ; //Azul
    tulPetaloIzq = new Petalo() ;
    tulPetaloIzq -> setColorPetalo({0,1,1}) ; //Cian. MOVER ESTE PETALO
    tulCentro = new Esfera(20,20,20.0) ;
    tulCentro -> setColorSolido({0.5,0.5,0}) ;
    tulCentro -> setMaterial(new MaterialAmarillo()) ;
}

Flor::Flor(){
    florHoja = new Esfera(30,30,10.0) ;
    florHoja -> setColorSolido({0,1,0}) ;
    florHoja -> setMaterial(new MaterialVerde()) ;
    florTallo = new Cilindro(1,20,30.0,10.0) ;
    florTallo -> setColorSolido({0,1,0}) ;
    florTallo -> setMaterial(new MaterialVerde()) ;
    florTulipa = new Tulipa() ;
}

Pierna::Pierna(){
    piePlanta = new Cubo(20.0) ;
    piePlanta -> setColorSolido({1,0.5,0}) ;
    piePlanta -> setMaterial(new MaterialNaranja()) ;
    pieEsfera = new Esfera(20,20,20.0) ;
    pieEsfera -> setColorSolido({0.95,0.95,0.95}) ;
    pieEsfera -> setMaterial(new MaterialBlanco()) ;
    pieCilindro = new Cilindro(1,20,30.0,20.0) ;
    pieCilindro -> setColorSolido({1,0.5,0}) ;
    pieCilindro -> setMaterial(new MaterialNaranja()) ;
}

Cuerpo::Cuerpo(){
    rotacionAlfa = 0 ;
    rotacionOmega = 0 ;
    alfa = false ;
    omega = false ;
    cuerCentro = new Esfera(20,20,20.0) ;
    cuerCentro -> setColorSolido({0.95,0.95,0.95}) ;
    cuerCentro -> setMaterial(new MaterialBlanco()) ;
    cuerCola = new Cono(1,20,30.0,20.0) ;
    cuerCola -> setColorSolido({0.95,0.95,0.95}) ;
    cuerCola -> setMaterial(new MaterialBlanco()) ;
    cuerPieDer = new Pierna() ;
    cuerPieIzq = new Pierna() ;
}

Cabeza::Cabeza(){
    cabCentro = new Esfera(20,20,20.0) ;
    cabCentro -> setColorSolido({0.95,0.95,0.95}) ;
    cabCentro -> setMaterial(new MaterialBlanco()) ;
    cabOjoDer = new Esfera(20,20,20.0) ;
    cabOjoDer -> setColorSolido({0,0,0}) ;
    cabOjoDer -> setMaterial(new MaterialNegro()) ;
    cabOjoIzq = new Esfera(20,20,20.0) ;
    cabOjoIzq -> setColorSolido({0,0,0}) ;
    cabOjoIzq -> setMaterial(new MaterialNegro()) ;
    cabPico = new Tetraedro(10.0) ;
    cabPico -> setColorSolido({1,0.5,0}) ;
    cabPico -> setMaterial(new MaterialNaranja()) ;
    cabFlor = new Flor() ;
}

Cuello::Cuello(){
    rotacionDelta = 0 ;
    rotacionEpsilon = 0 ;
    rotacionChi = 0 ;
    delta = false ;
    epsilon = false ;
    chi = false ;
    cueCabeza = new Cabeza() ;
    cueCentro = new Cilindro(1,20,30.0,20.0) ;
    cueCentro -> setColorSolido({0.95,0.95,0.95}) ;
    cueCentro -> setMaterial(new MaterialBlanco()) ;
}

Ganso::Ganso(){
    rotacionBeta = 0 ;
    rotacionGamma = 0 ;
    beta = false ;
    gamma = false ;
    ganCuello = new Cuello() ;
    ganCuerpo = new Cuerpo() ;
}

/*Funciones de dibujado*/
void Petalo::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glTranslatef(-30,30,0) ;
        glRotatef(45,0,0,1) ;
        glScalef(0.2,2,1) ;
        petEsfera -> draw(modoDib, modos) ;
    glPopMatrix() ;
}
void Tulipa::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glPushMatrix() ;
            tulPetaloAbajo -> draw(modoDib, modos) ;
        glPopMatrix() ;
            glRotatef(90.0,0,1,0) ;
            tulPetaloDer -> draw(modoDib, modos) ;
        glPushMatrix() ;
            glRotatef(180.0,0,1,0) ;
            tulPetaloArriba -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(-caidaPetaloX,-caidaPetaloY,0) ;
            glRotatef(100.0,0,1,0) ;
            tulPetaloIzq -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(0,30,0) ;
            glScalef(1.0,1.0,1.0) ;
            tulCentro -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}

void Flor::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glPushMatrix() ;
            glTranslatef(20,-20,0) ;
            glScalef(2.0,1.0,0.3) ;
            florHoja -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(0,-100,0) ;
            glScalef(0.4,4.0,0.4) ;
            florTallo -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            florTulipa -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}

void Pierna::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glTranslatef(0,-100,0) ;
        glPushMatrix() ;
            glTranslatef(10,0,0) ;
            glScalef(4,0.6,2) ;
            piePlanta -> draw(modoDib, modos) ;
        glPopMatrix () ;
        glPushMatrix() ;
            glTranslatef(0,5,0) ;
            glScalef(0.4,2,0.4) ;
            pieCilindro -> draw(modoDib, modos) ;
        glPopMatrix () ;
        glPushMatrix() ;
            glTranslatef(0,90,0) ;
            glScalef(1.5,2,1.3) ;
            pieEsfera -> draw(modoDib, modos) ;
        glPopMatrix () ;
    glPopMatrix() ;
}

void Cuerpo::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glPushMatrix() ;
            glTranslatef(0,-30,-60) ;
            glRotatef(rotacionAlfa,0,0,1) ;
            cuerPieDer -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(0,-30,60) ;
            glRotatef(rotacionOmega,0,0,1) ;
            cuerPieIzq -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glRotatef(3,0,0,1) ;
            glScalef(6,4,4) ;
            cuerCentro -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(-95,0,0) ;
            glRotatef(90,0,0,1) ;
            glScalef(2.3,2.3,2.3) ;
            cuerCola -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}

void Cabeza::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glTranslatef(40,0,0) ;
        glPushMatrix() ;
            glScalef(3.0,2.0,2.0) ;
            cabCentro -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(25,20,30) ;
            glScalef(0.4,0.4,0.4) ;
            cabOjoDer -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(25,20,-30) ;
            glScalef(0.4,0.4,0.4) ;
            cabOjoIzq -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(60,0,0) ;
            glRotatef(-90,1,0,0) ;
            glRotatef(-90.0,0,0,1) ;
            glScalef(4,4,4) ;
            cabPico -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glTranslatef(60,-3,-35) ;
            glRotatef(180,0,0,1) ;
            glRotatef(-90,0,1,0) ;
            glRotatef(90.0,0,0,1) ;
            glScalef(0.6,0.6,0.6) ;
            cabFlor -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}

void Cuello::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glPushMatrix() ;
            glPushMatrix() ;
                glRotatef(-40,0,0,1) ;
                glTranslatef(0,20,0) ;
                glScalef(0.8,5,0.8) ;
                cueCentro -> draw(modoDib, modos) ;
            glPopMatrix() ;
        glPopMatrix() ;

        glPushMatrix() ;
            glTranslatef(100,120,0) ;
            glRotatef(-10,0,1,1) ;
            glRotatef(rotacionDelta,1,0,0) ;
            glRotatef(rotacionEpsilon,0,1,0) ;
            glRotatef(rotacionChi,0,0,1) ;
            cueCabeza -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}

void Ganso::draw(int modoDib, std::vector<bool>  modos){
    glPushMatrix() ;
        glPushMatrix() ;
            glTranslatef(90,30,0) ;
            glRotatef(rotacionBeta,1,0,0) ;
            glRotatef(rotacionGamma,0,0,1) ;
            ganCuello -> draw(modoDib, modos) ;
        glPopMatrix() ;
        glPushMatrix() ;
            glScalef(1.1,1.1,1.1) ;
            ganCuerpo -> draw(modoDib, modos) ;
        glPopMatrix() ;
    glPopMatrix() ;
}


/*Funciones de alteración de elementos*/
void Petalo::setColorPetalo(Tupla3f color){
    petEsfera -> setColorSolido (color) ;
}

void Tulipa::caerPetalo(float incremento_x, float incremento_y){
    caidaPetaloX += incremento_x ;
    caidaPetaloY += incremento_y ;
}

void Cuerpo::rotarPiernaDerecha(float incremento_z){
    if (rotacionAlfa >= 40){rotacionAlfa = rotacionAlfa - incremento_z ; alfa = false ;}
    else if (rotacionAlfa <= -40) {rotacionAlfa = rotacionAlfa + incremento_z ; alfa = true ;}
    alfa ? rotacionAlfa = rotacionAlfa + incremento_z : rotacionAlfa = rotacionAlfa - incremento_z;
}
void Cuerpo::rotarPiernaIzquierda(float incremento_z){
    if (rotacionOmega >= 40){rotacionOmega = rotacionOmega - incremento_z ; omega = true ;}
    else if (rotacionOmega <= -40) {rotacionOmega = rotacionOmega + incremento_z ; omega = false ;}
    omega ? rotacionOmega = rotacionOmega - incremento_z : rotacionOmega = rotacionOmega + incremento_z;
}
void Cuello::rotarCabeza(float incremento_x, float incremento_y, float incremento_z){
    if (rotacionDelta >= 40){rotacionDelta = rotacionDelta - incremento_x ; delta = false ;}
    else if (rotacionDelta <= -40) {rotacionDelta = rotacionDelta + incremento_x ; delta = true ;}
    delta ? rotacionDelta = rotacionDelta + incremento_x : rotacionDelta = rotacionDelta - incremento_x;

    if (rotacionEpsilon >= 40){rotacionEpsilon = rotacionEpsilon - incremento_y ; epsilon = false ;}
    else if (rotacionEpsilon <= -40) {rotacionEpsilon = rotacionEpsilon + incremento_y ; epsilon = true ;}
    epsilon ? rotacionEpsilon = rotacionEpsilon + incremento_y : rotacionEpsilon = rotacionEpsilon - incremento_y;

    if (rotacionChi >= 40){rotacionChi = rotacionChi - incremento_z ; chi = false ;}
    else if (rotacionChi <= -40) {rotacionChi = rotacionChi + incremento_z ; chi = true ;}
    chi ? rotacionChi = rotacionChi + incremento_z : rotacionChi = rotacionChi - incremento_z;
}
void Ganso::rotarCuello(float incremento_x , float incremento_z){
    if (rotacionBeta >= 20){rotacionBeta = rotacionBeta - incremento_x ; beta = false ;}
    else if (rotacionBeta <= -20) {rotacionBeta = rotacionBeta + incremento_x ; beta = true ;}
    beta ? rotacionBeta = rotacionBeta + incremento_x : rotacionBeta = rotacionBeta - incremento_x;

    if (rotacionGamma >= 20){rotacionGamma = rotacionGamma - incremento_z ; gamma = false ;}
    else if (rotacionGamma <= -20) {rotacionGamma = rotacionGamma + incremento_z ; gamma = true ;}
    gamma ? rotacionGamma = rotacionGamma + incremento_z : rotacionGamma = rotacionGamma - incremento_z;
}

/*Funciones de redireccion a estos primeros*/

void Flor::caerPetalo(float incremento_x, float incremento_y){
    florTulipa -> caerPetalo(incremento_x,incremento_y) ;
}
void Cabeza::caerPetalo(float incremento_x, float incremento_y){
    cabFlor -> caerPetalo(incremento_x,incremento_y) ;
}
void Cuello::caerPetalo(float incremento_x, float incremento_y){
    cueCabeza -> caerPetalo(incremento_x,incremento_y) ;
}
void Ganso::caerPetalo(float incremento_x, float incremento_y){
    ganCuello -> caerPetalo(incremento_x,incremento_y) ;
}

void Ganso::rotarPiernaDerecha(float incremento_z){
    ganCuerpo -> rotarPiernaDerecha (incremento_z) ;
}
void Ganso::rotarPiernaIzquierda(float incremento_z){
    ganCuerpo -> rotarPiernaIzquierda (incremento_z) ;
}

void Ganso::rotarCabeza(float incremento_x, float incremento_y, float incremento_z){
    ganCuello -> rotarCabeza(incremento_x,incremento_y,incremento_z) ;
}
