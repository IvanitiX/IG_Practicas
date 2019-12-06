#include "materiales.h"

MaterialMagenta::MaterialMagenta() : Material({0.8945,0.0352,0.4961,0.7},{0.8945,0.0352,0.4961,0.5},{0.8945,0.0352,0.4961,0.9},128.0) {}

MaterialAmarillo::MaterialAmarillo() : Material({1.0,0.6406,0.125,0.9},{1.0,0.6406,0.125,0.9},{1.0,0.6406,0.125,0.9},90.0) {}

MaterialCian::MaterialCian() : Material({0.0,0.6484,0.8359,0.1},{0.0,0.6484,0.8359,0.9},{0.0,0.6484,0.8359,0.5},70.0) {}

MaterialUltraDifuso::MaterialUltraDifuso() : Material ({0.883,0.688,0.352,0.5},{0.883,0.688,0.352,1.0},{0.883,0.688,0.352,1.0},10.0) {}

MaterialUltraEspecular::MaterialUltraEspecular() : Material ({0.441,0.441,0.441,1.0},{0.441,0.441,0.441,0.5},{0.441,0.441,0.441,1.0},20.0) {}