#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado)
{

   // inicializar la tabla de vértices

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)


   // inicializar la tabla de vértices
   v =  {  { -lado/2, -lado/2, -lado/2 }, // 0
                  { -lado/2, -lado/2, +lado/2 }, // 1
                  { -lado/2, +lado/2, -lado/2 }, // 2
                  { -lado/2, +lado/2, +lado/2 }, // 3
                  { +lado/2, -lado/2, -lado/2 }, // 4
                  { +lado/2, -lado/2, +lado/2 }, // 5
                  { +lado/2, +lado/2, -lado/2 }, // 6
                  { +lado/2, +lado/2, +lado/2 }  // 7
               };

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

   f = { { 0, 2, 4 }, { 4, 2, 6 },
                  { 1, 5, 3 }, { 3, 5, 7 },
                  { 1, 3, 0 }, { 0, 3, 2 },
                  { 5, 4, 7 }, { 7, 4, 6 },
                  { 1, 0, 5 }, { 5, 0, 4 },
                  { 3, 7, 2 }, { 2, 7, 6 }
                } ;

   colores_solido = {{255,0,0},{255,0,0},{255,0,0},{255,0,0},
              {255,0,0},{255,0,0},{255,0,0},{255,0,0}} ;
   colores_linea = {{0,255,0},{0,255,0},{0,255,0},{0,255,0},
               {0,255,0},{0,255,0},{0,255,0},{0,255,0}} ;
   colores_puntos = {{0,0,255},{0,0,255},{0,0,255},{0,0,255},
               {0,0,255},{0,0,255},{0,0,255},{0,0,255}} ;
   colores_ajedrez_par = {{227,0,82},{227,0,82},{227,0,82},{227,0,82}} ;
   colores_ajedrez_impar = {{0,0,0},{0,0,0},{0,0,0},{0,0,0}} ;

}

