#include "camara.h"

Camara::Camara(Tupla3f cameye, Tupla3f camat, Tupla3f camup, int camtipo, 
                float camizq, float camder, float camcer, float camlej,
                float camarr, float camaba){
    eye = cameye ;
    at = camat ;
    up = camup ;
    tipo = camtipo ;
    left = camizq ;
    right = camder ;
    top = camarr ;
    bottom = camaba ;
    near = camcer ;
    far = camlej ;
}

void Camara::setProyeccion(){
    if (tipo == 0){
        glFrustum(left,right,bottom,top,near,far) ;
        //gluPerspective(atan(right/near)*360.0*PI,right/top,near,far) ;
    }
    if (tipo == 1){
        glOrtho(left,right,bottom,top,near,far) ;
    }
}

void Camara::setObserver(){
    gluLookAt(eye[0],eye[1],eye[2],
               at[0],at[1],at[2],
               up[0],up[1],up[2]) ;
}

void Camara::zoom(float factor){
    if (factor > 0){
        left *= factor ;
        right *= factor ;
        top *= factor ;
        bottom *= factor ;
        std::cout << "Zoom @ " << factor  << "L/R/T/B " << left << " / " << right << " / " << top << " / " << bottom << std::endl ;
    }
}

void Camara::rotarXExaminar(float anguloX){
    glRotatef(anguloX,1,0,0) ;
}

void Camara::rotarYExaminar(float anguloY){
    glRotatef(anguloY,0,1,0) ;
}

void Camara::rotarZExaminar(float anguloZ){
    glRotatef(anguloZ,0,0,1) ;
}

void Camara::mover(float x, float y, float z){
    eye = Tupla3f(x,y,z) ;
}

void Camara::girar(float x, float y){
    rotarXFirstPerson(x);
    //rotarYFirstPerson(y) ;
}

void Camara::rotarXFirstPerson(float anguloX){
    Tupla3f n, u, v;

	float modulo_u, modulo_v, modulo_n;

	float x, y, z, s;

	n = eye - at;
	modulo_n = sqrt(n(0)*n(0) + n(1)*n(1) + n(2)*n(2));
	n = {n(0)/modulo_n, n(1)/modulo_n, n(2)/modulo_n};

	up = up - at;
	u = up.cross(n);
	modulo_u = sqrt(u(0)*u(0) + u(1)*u(1) + u(2)*u(2));
	u = {u(0)/modulo_u, u(1)/modulo_u, u(2)/modulo_u};

	v = n.cross(u);
	modulo_v = sqrt(v(0)*v(0) + v(1)*v(1) + v(2)*v(2));
	v = {v(0)/modulo_v, v(1)/modulo_v, v(2)/modulo_v};

    s = u.scalar(v.cross(n),3) ;

	eye = {eye.scalar(u,3), eye.scalar(v,3), eye.scalar(n,3)};
	eye = {(float)cos(anguloX*PI/180)*eye(0) - (float)sin(anguloX*PI/180)*eye(2), eye(1), (float)sin(anguloX*PI/180)*eye(0) + (float)cos(anguloX*PI/180)*eye(2)};
    x = eye[0] * u[0] + eye[1] * v[0] + eye[2] * n[0] ;
    y = eye[0] * u[1] + eye[1] * v[1] + eye[2] * n[1] ;
    z = eye[0] * u[2] + eye[1] * v[2] + eye[2] * n[2] ;
	eye = {x/s, y/s, z/s};


	up = {up.scalar(u,3), up.scalar(v,3), up.scalar(n,3)};
	up = {(float)cos(anguloX*PI/180)*up(0) - (float)sin(anguloX*PI/180)*up(2), up(1), (float)sin(anguloX*PI/180)*up(0) + (float)cos(anguloX*PI/180)*up(2)};
    x = up[0] * u[0] + up[1] * v[0] + up[2] * n[0] ;
    y = up[0] * u[1] + up[1] * v[1] + up[2] * n[1] ;
    z = up[0] * u[2] + up[1] * v[2] + up[2] * n[2] ;
	float up_normal = sqrt(x*x + y*y + z*z);
	up = {x/s/up_normal, y/s/up_normal, z/up_normal};
}

void Camara::rotarYFirstPerson(float anguloY){
   Tupla3f u = (at-eye);
    u = u.cross(up) ;
    float mod_u = sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]) ;
    u = {u[0]/mod_u,u[1]/mod_u,u[2]/mod_u} ;
    float x,y,z ;
    x = eye[0] * (cos(0.0)+(pow(u[0],2)*(1-cos(0.0)))) + eye[1] * (u[1]*u[0]*(0.0) + u[2]*sin(0.0)) + eye[2] * (u[2]*u[0]*(1-cos(0.0)) - u[1]*sin(0.0)) ;
    y = eye[0] * (u[0]*u[1]*(1-cos(anguloY*PI/180.0)) - u[2]*sin(anguloY*PI/180.0)) + eye[1] * (cos(anguloY*PI/180.0)+(pow(u[1],2)*(1-cos(anguloY*PI/180.0)))) 
        + eye[2] * (u[2]*u[1]*(1-cos(anguloY*PI/180.0)) + u[0]*sin(anguloY*PI/180.0)) ;
    z = eye[0] * (u[0]*u[2]*(1-cos(0.0)) + u[1]*sin(0.0)) + eye[1] * (u[1]*u[2]*(1-cos(0.0)) - u[0]*sin(0.0)) + eye[2] * (cos(0.0)+(pow(u[2],2)*(1-cos(0.0)))) ;
    eye = {x,y,z} ;
}