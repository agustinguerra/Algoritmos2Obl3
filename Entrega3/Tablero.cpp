#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"

Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	this->prio = p;
	this->elTablero = bloques;
}
	
nat Tablero::CalcularPrioridad()
{
	Matriz<int> matrizCopia(this->elTablero.ObtenerAncho(), this->elTablero.ObtenerAncho());
	int lar = elTablero.ObtenerLargo();
	for (int i = 0; i < lar; i++) {
		for (int j = 0; j < lar; j++) {
			matrizCopia[i][j] = elTablero[i][j];
		}
	}
	Tablero tableroCopia = Tablero(matrizCopia, this->prio);
	return this->prio->CalcularPrioridad(tableroCopia);
}
		
nat Tablero::ObtenerCantidadDeMovimientos()
{

	// Implementar.
	return 0;
}

bool Tablero::operator==(const Tablero& t ) const
{
	if (t.ObtenerTablero().ObtenerAncho() != this->elTablero.ObtenerAncho()) {
		return false;
	}
	else {
		int lar = elTablero.ObtenerLargo();
		for (int i = 0; i < lar; i++) {
			for (int j = 0; j < lar; j++) {
				if (t.ObtenerTablero()[i][j] != elTablero[i][j]) {
					return false;
				}
			}
		}
	}
	return true;
}
	

Iterador<Tablero> Tablero::Vecinos()
{
	// Implementar.
	return NULL;
}
	

Matriz<int> Tablero::ObtenerTablero() const
{
	return elTablero;
}

Cadena Tablero::Imprimir() const
{
	// Implementar.
	return "";
}


#endif