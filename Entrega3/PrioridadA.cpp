#ifndef PRIORIDAD_A_CPP
#define PRIORIDAD_A_CPP

#include "PrioridadA.h"


nat PrioridadA::CalcularPrioridad(const Tablero& t) const 
{
	int lar = t.ObtenerTablero().ObtenerLargo();
	int contador = 1;
	int retorno = 0;
	Iterador<Array<int>> iterador = t.ObtenerTablero().ObtenerIterador();
	for (int i = 0; i < lar; i++) {
		for (int j = 0; j < lar; j++) {
			if (contador == iterador.ElementoActual()[j]) {
			}
			else {
				retorno++;
			}
			contador++;
		}
		iterador.Avanzar();
	}
	// Implementar.
	return retorno;
}


#endif