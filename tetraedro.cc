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
			{-Size/2,-Size/2,-Size/2},		//0
			{0,-Size/2,Size/2},		//1
			{Size/2,-Size/2,-Size/2},		//2
			{0,Size/2,0} //3
		};

	f = {{0,1,3}, {1,2,3}, {2,0,3}, {0,2,1}};

	solido = { 0,0.5,0.5} ;
	linea = {0,1,0} ;
	puntos = {0,0,1} ;

	color_impar_ajedrez = {0,0.5,0.5} ;
    color_par_ajedrez = {0,0,0} ;

	MaterialCian * mc = new MaterialCian() ;
	material = mc ;

	//ColorearObjeto();

	//calcular_normales();
}

