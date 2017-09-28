#ifndef PRIORIDAD_B_CPP
#define PRIORIDAD_B_CPP

#include "PrioridadB.h"


nat PrioridadB::CalcularPrioridad(const Tablero& t) const
{
	int prioridad = 0;
	int largo = t.ObtenerTablero().ObtenerAncho();
	int contador = 1;

	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			for (int k = 0; k < largo; k++) {
				for (int q = 0; q < largo; q++) {
					if (t.ObtenerTablero()[k][q] == contador) {
						if (k - q < 0) {
							prioridad += (k - q)*(-1);
						}
						else {
							prioridad += (k - q);
						}
					}
				}
			}
			contador++;
		}
	}
	return prioridad;
}


#endif