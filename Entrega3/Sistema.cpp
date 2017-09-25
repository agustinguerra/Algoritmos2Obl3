#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"

Sistema::Sistema()
{
}

void Sistema::EstablecerTableroInicial(Tablero inicial)
{
	this->tableroInicial = inicial;
	int tamano = inicial.ObtenerTablero().ObtenerAncho();
	Matriz<int> mTablero(tamano);
	int contador = 1;
	for (int i = 0; i < tamano; i++) {
		for (int j = 0; j < tamano - 1; j++) {
			mTablero[i][j] = contador;
			contador++;
		}
	}
	Tablero tabFinal = Tablero(mTablero, nullptr);
	this->tableroFinal = tabFinal;
	Puntero<ColaPrioridadExtendidaImp<Puntero<NodoTablero>,int>> cp = new ColaPrioridadExtendidaImp<Puntero<NodoTablero>,int>(nullptr, Comparador<int>::Default, Comparador<int>::Default);
	this->cp = cp;
	Puntero<NodoTablero> nodoUno = new NodoTablero(inicial);
	cp->InsertarConPrioridad(nodoUno, nodoUno->dato.CalcularPrioridad());
	if (TieneSolucion()) {
		Solucionar();
	}
}

bool Sistema::TieneSolucion()
{
	//Implementar.
	return false;
}
	
int Sistema::Movimientos()
{
	return this->tableroInicial.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	Puntero<NodoTablero> primerT = cp->EliminarElementoMayorPrioridad();
	cp->Vaciar();

	return NULL;
}


#endif