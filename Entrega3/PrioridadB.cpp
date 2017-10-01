#ifndef PRIORIDAD_B_CPP
#define PRIORIDAD_B_CPP

#include "PrioridadB.h"


nat PrioridadB::CalcularPrioridad(const Tablero& t) const
{
	int prioridad = 0;
	int largo = t.ObtenerTablero().ObtenerAncho();

	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			if (t.ObtenerTablero()[i][j] != 0) {
				int numero = t.ObtenerTablero()[i][j] - 1;
				int columnaEstar = (numero%largo);
				int filaEstar = (numero / largo);
				if (i - filaEstar > 0) {
					prioridad = prioridad + (i - filaEstar);
				}
				else {
					prioridad = prioridad + (i - filaEstar)*(-1);
				}
				if (j - columnaEstar > 0) {
					prioridad = prioridad + (j - columnaEstar);
				}
				else {
					prioridad = prioridad + (j - columnaEstar)*(-1);		
				}
			}
		}
	}
	return prioridad;
}


#endif