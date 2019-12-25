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
   v =  {         { -lado/2, -lado/2, -lado/2 }, // 0
                  { -lado/2, -lado/2, +lado/2 }, // 1
                  { -lado/2, +lado/2, -lado/2 }, // 2
                  { -lado/2, +lado/2, +lado/2 }, // 3
                  { +lado/2, -lado/2, -lado/2 }, // 4
                  { +lado/2, -lado/2, +lado/2 }, // 5
                  { +lado/2, +lado/2, -lado/2 }, // 6
                  { +lado/2, +lado/2, +lado/2 },  // 7
                  {-lado/2, -lado/2, +lado/2}, //8
                  {+lado/2, -lado/2, +lado/2}, //9
                  {-lado/2, +lado/2, +lado/2}, //10
                  {+lado/2, +lado/2, +lado/2}, //11
                  {-lado/2, -lado/2, -lado/2}, //12
                  {+lado/2, -lado/2, -lado/2}, //13
                  {-lado/2, +lado/2, -lado/2}, //14
                  {+lado/2, +lado/2, -lado/2}, //15
                  {-lado/2, -lado/2, +lado/2}, //16
                  {+lado/2, -lado/2, +lado/2}, //17
                  {-lado/2, -lado/2, -lado/2}, //18
                  {+lado/2, -lado/2, -lado/2}, //19
                  {-lado/2, +lado/2, +lado/2}, //20
                  {+lado/2, +lado/2, +lado/2}, //21
                  {-lado/2, +lado/2, -lado/2}, //22
                  {+lado/2, +lado/2, -lado/2}, //23
               };

   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)

  /* f = { { 0, 2, 4 }, { 4, 2, 6 },
                  { 1, 5, 3 }, { 3, 5, 7 },
                  { 1, 3, 0 }, { 0, 3, 2 },
                  { 5, 4, 7 }, { 7, 4, 6 },
                  { 1, 0, 5 }, { 5, 0, 4 },
                  { 3, 7, 2 }, { 2, 7, 6 }
                } ;*/

   f = {{0,1,2}, {3,2,1}, 
       {4,6,5}, {6,7,5}, 
       {8,11,10}, {11,8,9}, 
       {12,14,15}, {12,15,13},
       {16,18,17}, {17,18,19},
       {20,21,22}, {22,21,23}} ;
               
   ct = {{0,0},{0,1},{1,0},{1,1}, {0,0},{0,1},{1,0},{1,1}, 
         {0,0},{0,1},{1,0},{1,1}, {0,0},{0,1},{1,0},{1,1},
         {0,0},{0,1},{1,0},{1,1}, {0,0},{0,1},{1,0},{1,1}} ;

   solido = {1,0,0} ;
   linea = {0,1,0} ;
   puntos = {0,0,1} ;

   color_impar_ajedrez = {1,0.25,1} ;
   color_par_ajedrez = {0,0,0} ;

   material = new MaterialVerde() ;
}

