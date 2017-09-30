#pragma once

#include "Tablero.h"

class NodoTablero {
public:
	Tablero dato;
	Puntero<NodoTablero> padre;
	NodoTablero(const Tablero&dato) : dato(dato), padre(nullptr) {  };
};