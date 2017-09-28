#pragma once

#include "Tablero.h"

class NodoTablero {
public:
	Tablero dato;
	Puntero<NodoTablero> padre;
	NodoTablero(Tablero&dato) : dato(dato), padre(nullptr) {  };
};