#include "materiales.h"

MaterialMagenta::MaterialMagenta() : Material({0.8945,0.0352,0.4961,0.7},{0.8945,0.0352,0.4961,0.5},{0.8945,0.0352,0.4961,0.9},128.0) {}

MaterialAmarillo::MaterialAmarillo() : Material({1.0,0.6406,0.125,0.9},{1.0,0.6406,0.125,0.9},{1.0,0.6406,0.125,0.9},90.0) {}

MaterialCian::MaterialCian() : Material({0.0,0.6484,0.8359,0.1},{0.0,0.6484,0.8359,0.9},{0.0,0.6484,0.8359,0.5},70.0) {}

MaterialUltraDifuso::MaterialUltraDifuso() : Material ({0.883,0.688,0.352,0.5},{0.883,0.688,0.352,1.0},{0.883,0.688,0.352,1.0},10.0) {}

MaterialUltraEspecular::MaterialUltraEspecular() : Material ({0.441,0.441,0.441,1.0},{0.441,0.441,0.441,0.5},{0.441,0.441,0.441,1.0},20.0) {}

MaterialNaranja::MaterialNaranja() : Material ({0.780392,0.568627,0.113725,1.0},{0.992157,0.941176,0.807843,1},{0.329412,0.223529,0.027451,1.0},27.89) {}

MaterialNegro::MaterialNegro() : Material ({0.2,0.2,0.2,1.0},{0.3,0.3,0.3,1.0},{0,0,0,1.0},20.0) {}

MaterialBlanco::MaterialBlanco() : Material ({1,0.829,0.829,1.0},{0.296648,0.296648,0.296648,1.0},{0.75,0.79275,0.79275,1.0}, 10.24) {}

MaterialVerde::MaterialVerde() : Material ({0.0,0.3,0.0,1.0}, {0.0,0.5,0.0,1.0}, {0.0,0.7,0.0,1.0}, 100.0) {}