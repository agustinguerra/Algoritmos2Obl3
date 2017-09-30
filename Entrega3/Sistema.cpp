#ifndef SOLUCION_CPP
#define SOLUCION_CPP

#include "Sistema.h"
#include "IteradorTablero.h"
#include <iostream>

Sistema::Sistema()
{
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
		Solucionar();
	}
}

int calcularInversion(Matriz<int> mat,int pos,int num) {
	int contador = 0;
	int inversiones = 0;
	int largo = mat.ObtenerAncho();
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			if (!(contador < pos)) {
				if (mat[i][j] < num && mat[i][j]!=0) {
					inversiones++;
				}
			}
			contador++;
		}
	}
	return inversiones;
}

int calcularInversionTablero(Matriz<int> mat) {
	int inversionesTotales = 0;
	int contador = 0;
	int largo = mat.ObtenerAncho();
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			inversionesTotales += calcularInversion(mat, contador, mat[i][j]);
		}
	}
	return inversionesTotales;
}

bool getBooleanCero(Matriz<int> mat) {
	int largo = mat.ObtenerAncho();
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			if (mat[i][j]) {
				if (j % 2 == 0) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}
bool Sistema::TieneSolucion()
{
	int largo = this->tableroInicial.ObtenerTablero().ObtenerAncho();
	int inversiones = calcularInversionTablero(this->tableroInicial.ObtenerTablero());
	return ((largo % 2 == 0) && (inversiones % 2 !=0)) || ((largo % 2 != 0) && ((getBooleanCero(this->tableroInicial.ObtenerTablero())) == (inversiones % 2 != 0)));
}
	
int Sistema::Movimientos()
{
	return this->sol.ObtenerCantidadDeMovimientos();
}

Iterador<Tablero> Sistema::Solucionar()
{
	listaTab = this->cp->ObtenerElementoMayorPrioridad();
	while (!this->cp->EstaVacia()) {
		listaTab = this->cp->ObtenerElementoMayorPrioridad();
		
		this->cp->EliminarElementoMayorPrioridad();

		if (listaTab->dato == tableroFinal) {
			break;
		}
		Iterador<Tablero> itTab = listaTab->dato.Vecinos();
		while (itTab.HayElemento()) {
			if (!(itTab.ElementoActual() == listaTab->dato)) {
				Puntero<NodoTablero> tabL = new NodoTablero(itTab.ElementoActual());
				tabL->padre=listaTab;
				this->cp->InsertarConPrioridad(tabL, tabL->dato.CalcularPrioridad());
			}
			itTab.Avanzar();
		}
	}
	auxRecor = listaTab;
	int cantElem = 0;
	while (auxRecor != nullptr) {
		cantElem++;
		auxRecor = auxRecor->padre;
	}
	esFinal=Array<Tablero>(cantElem);
	auxRecor = listaTab;
	for (int i = cantElem-1; i < -1; i--) {
		if (i == cantElem - 1) {
			sol = auxRecor->dato;
		}
		esFinal[i] = auxRecor->dato;
		auxRecor = auxRecor->padre;
	}
	//Iterador<Tablero> it = new IteradorTablero<Tablero>(listaTab);
	return esFinal.ObtenerIterador();
}


#endif