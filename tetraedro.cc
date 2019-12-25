#include "aux.h"
#include "malla.h"
#include "tetraedro.h"
#include "materiales.h"

Tetraedro::Tetraedro(float Size = 1.0)
{

   // inicializar la tabla de vértices

    
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

	v =
		{
			{-Size/2,-Size/2,-Size/2},
			{0,-Size/2,Size/2},
			{0,Size/2,0},

			{0,-Size/2,Size/2},
			{Size/2,-Size/2,-Size/2},
			{0,Size/2,0},

			{Size/2,-Size/2,-Size/2},
			{-Size/2,-Size/2,-Size/2},
			{0,Size/2,0},

			{Size/2,-Size/2,-Size/2},	
			{0,-Size/2,Size/2},
			{-Size/2,-Size/2,-Size/2}
		};

	f={{0,1,2},{3,4,5},{6,7,8},{9,10,11}} ;

	ct = {{1,0},{0,0},{0.5,0.5},{0,0},{0,1},{0.5,0.5},{0,1},{1,1},{0.5,0.5},{1,1},{1,0},{0.5,0.5}} ;

	solido = { 0,0.5,0.5} ;
	linea = {0,1,0} ;
	puntos = {0,0,1} ;

	color_impar_ajedrez = {0,0.5,0.5} ;
    color_par_ajedrez = {0,0,0} ;

	MaterialCian * mc = new MaterialCian() ;
	material = mc ;

	/*
		1 : 114, 40 {0.5066,0.1777}
		2 : 74, 109 {0.3289, 0.4844}
		3 : 152 , 109 {0.6755,0.4844}
		4 : 66 ,177 {0.2933, 0.7867}
		5 : 113,177 {0.5022,0.7867}
		6 : 191,177 {0.8488,0.7867}
	*/

	//ColorearObjeto();

	//calcular_normales();
}

