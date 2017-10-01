#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"
#include "IteradorTablero.h"
#include <iostream>

Sistema::Sistema()
{
}

Array<int> aplanarElTablero(Matriz<int> mat)
{
	int largo = mat.Largo;

	Array<int>arrayDeTablero(largo*largo, 0);

	int contador = 0;
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			arrayDeTablero[contador] = mat[i][j];
			contador++;
		}
	}
	return arrayDeTablero;
}

int calcularInversionTablero(Matriz<int> mat) {
	int inversionesTotales = 0;
	int contador = 0;
	Array<int> aplanado = aplanarElTablero(mat);
	int largo = aplanado.Largo;
	for (int i = 0; i < largo - 1; i++) {
		for (int j = i + 1; j < largo; j++) {
			if (aplanado[i] != 0 && aplanado[j] != 0 && aplanado[i] > aplanado[j]) {
				inversionesTotales++;
			}

		}
	}
	return inversionesTotales;
}

bool getBooleanCero(Matriz<int> mat) {
	int largo = mat.ObtenerAncho();
	int columnFromBottom = 0;
	for (int i = largo - 1; i > -1; i--) {
		for (int j = largo - 1; j > -1; j--) {
			if (mat[i][j] == 0) {
				columnFromBottom = i;
			}
		}
	}
	return (!((columnFromBottom + 1) % 2 == 0));
}


void Sistema::EstablecerTableroInicial(Tablero inicial)
{
	this->tableroInicial = inicial;
	int tamano = inicial.ObtenerTablero().ObtenerAncho();
	Matriz<int> mTablero(tamano);
	int contador = 1;
	int cantCuad = tamano*tamano;
	for (int i = 0; i < tamano; i++) {
		for (int j = 0; j < tamano; j++) {
			if (contador==cantCuad) {
				mTablero[i][j] = 0;
			}
			else {
				mTablero[i][j] = contador;
				contador++;
			}
			
		}
	}
	Tablero tabFinal = Tablero(mTablero, nullptr);
	this->tableroFinal = tabFinal;
	Puntero<ColaPrioridadExtendidaImp<Puntero<NodoTablero>,int>> cp = new ColaPrioridadExtendidaImp<Puntero<NodoTablero>,int>(nullptr,Comparador<Puntero<NodoTablero>>::Default, Comparador<int>::Default);
	this->cp = cp;
	Puntero<NodoTablero> nodoUno = new NodoTablero(inicial);
	cp->InsertarConPrioridad(nodoUno, nodoUno->dato.CalcularPrioridad());
	if (TieneSolucion()) {
		listaTab = this->cp->ObtenerElementoMayorPrioridad();
		while (!this->cp->EstaVacia()) {
			listaTab = this->cp->ObtenerElementoMayorPrioridad();

			this->cp->EliminarElementoMayorPrioridad();

			if (listaTab->dato == tableroFinal) {
				cantMovimientosFinal = listaTab->dato.ObtenerCantidadDeMovimientos();
				break;
			}
			Iterador<Tablero> itTab = listaTab->dato.Vecinos();
			while (itTab.HayElemento()) {
				if (!(itTab.ElementoActual() == listaTab->dato)) {
					Puntero<NodoTablero> tabL = new NodoTablero(itTab.ElementoActual());
					tabL->padre = listaTab;
					this->cp->InsertarConPrioridad(tabL, (tabL->dato.CalcularPrioridad()) + listaTab->dato.ObtenerCantidadDeMovimientos());
					//this->cp->InsertarConPrioridad(tabL, tabL->dato.CalcularPrioridad());
				}
				itTab.Avanzar();
			}
		}
	}
}


bool Sistema::TieneSolucion()
{
	int largo = this->tableroInicial.ObtenerTablero().ObtenerAncho();
	int inversiones = calcularInversionTablero(this->tableroInicial.ObtenerTablero());

	//bool conditionOne = (largo % 2 ==0) &&

	return (((largo % 2 != 0) && (inversiones % 2 ==0)) || ((largo % 2 == 0) && ((getBooleanCero(this->tableroInicial.ObtenerTablero())) == (inversiones % 2 == 0))));
}
	
int Sistema::Movimientos()
{
	return this->cantMovimientosFinal;
}

Iterador<Tablero> Sistema::Solucionar()
{
	auxRecor = listaTab;
	int cantElem = 0;
	while (auxRecor != nullptr) {
		cantElem++;
		auxRecor = auxRecor->padre;
	}
	esFinal=Array<Tablero>(cantElem);
	auxRecor = listaTab;
	for (int i = cantElem-1; i > -1; i--) {
		//if (i == cantElem - 1) {
		//	cantMovimientosFinal = auxRecor->dato.ObtenerCantidadDeMovimientos();
		//}
		esFinal[i] = auxRecor->dato;
		auxRecor = auxRecor->padre;
	}
	//Iterador<Tablero> it = new IteradorTablero<Tablero>(listaTab);
	return esFinal.ObtenerIterador();
}


#endif