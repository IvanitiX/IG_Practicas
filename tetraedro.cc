#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

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

	colores_solido = {{ 0,127,127},{ 0,127,127},{ 0,127,127},{ 0,127,127}} ;
	colores_linea = {{0,255,0},{0,255,0},{0,255,0},{0,255,0}} ;
	colores_puntos = {{0,0,255},{0,0,255},{0,0,255},{0,0,255}} ;
	colores_ajedrez_par = {{0,255,0},{0,255,0}} ;
	colores_ajedrez_impar = {{255,0,0},{255,0,0}} ;

	//ColorearObjeto();

	//calcular_normales();
}

