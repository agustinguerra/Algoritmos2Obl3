#ifndef TABLERO_CPP
#define TABLERO_CPP

#include "Tablero.h"
#include <string>


Tablero::Tablero(Matriz<int> bloques, Puntero<Prioridad> p)
{
	this->prio = p;
	this->elTablero = bloques;
	this->mov = 0;
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
	return (this->prio->CalcularPrioridad(tableroCopia)+mov);
}
		
nat Tablero::ObtenerCantidadDeMovimientos()
{
	return mov;
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
	//Busco el bloque vacio
	int xVac = 0;
	int yVac = 0;
	int largo = elTablero.ObtenerAncho();
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo; j++) {
			if (elTablero[i][j] == 0) {
				xVac = i;
				yVac = j;
			}
		}
	}
	bool arriba = false;
	bool abajo = false;
	bool izq = false;
	bool der = false;
	Tablero tableroCopiaArriba;
	Tablero tableroCopiaAbajo;
	Tablero tableroCopiaIzq;
	Tablero tableroCopiaDer;
	int contador = 0;
	int tam = elTablero.ObtenerAncho();
	if (yVac + 1<= tam) {
		contador++;
		Matriz<int> matrizCopiaArriba(this->elTablero.ObtenerAncho(), this->elTablero.ObtenerAncho());
		int lar = elTablero.ObtenerLargo();
		for (int i = 0; i < lar; i++) {
			for (int j = 0; j < lar; j++) {
				matrizCopiaArriba[i][j] = elTablero[i][j];
			}
		}
		matrizCopiaArriba[xVac][yVac] = matrizCopiaArriba[xVac][yVac + 1];
		matrizCopiaArriba[xVac][yVac] = 0;
		tableroCopiaArriba = Tablero(matrizCopiaArriba, this->prio);
		arriba = true;
	}
	if (yVac-1>-1) {
		contador++;
		Matriz<int> matrizCopiaAbajo(this->elTablero.ObtenerAncho(), this->elTablero.ObtenerAncho());
		int lar = elTablero.ObtenerLargo();
		for (int i = 0; i < lar; i++) {
			for (int j = 0; j < lar; j++) {
				matrizCopiaAbajo[i][j] = elTablero[i][j];
			}
		}
		matrizCopiaAbajo[xVac][yVac] = matrizCopiaAbajo[xVac][yVac - 1];
		matrizCopiaAbajo[xVac][yVac] = 0;
		tableroCopiaAbajo = Tablero(matrizCopiaAbajo, this->prio);
		abajo = true;
	}
	if (xVac-1>-1) {
		contador++;
		Matriz<int> matrizCopiaIzq(this->elTablero.ObtenerAncho(), this->elTablero.ObtenerAncho());
		int lar = elTablero.ObtenerLargo();
		for (int i = 0; i < lar; i++) {
			for (int j = 0; j < lar; j++) {
				matrizCopiaIzq[i][j] = elTablero[i][j];
			}
		}
		matrizCopiaIzq[xVac][yVac] = matrizCopiaIzq[xVac - 1][yVac];
		matrizCopiaIzq[xVac][yVac] = 0;
		tableroCopiaIzq = Tablero(matrizCopiaIzq, this->prio);
		izq = true;
	}
	if (xVac+1<= tam) {
		contador++;
		Matriz<int> matrizCopiaDer(this->elTablero.ObtenerAncho(), this->elTablero.ObtenerAncho());
		int lar = elTablero.ObtenerLargo();
		for (int i = 0; i < lar; i++) {
			for (int j = 0; j < lar; j++) {
				matrizCopiaDer[i][j] = elTablero[i][j];
			}
		}
		matrizCopiaDer[xVac][yVac] = matrizCopiaDer[xVac - 1][yVac];
		matrizCopiaDer[xVac][yVac] = 0;
		tableroCopiaDer = Tablero(matrizCopiaDer, this->prio);
		der = true;
	}
	Array<Tablero> arrayIteracion(contador);
	contador = 0;
	if (arriba) {
		arrayIteracion[contador] = tableroCopiaArriba;
		contador++;
	}
	if (abajo) {
		arrayIteracion[contador] = tableroCopiaAbajo;
		contador++;
	}
	if (der) {
		arrayIteracion[contador] = tableroCopiaDer;
		contador++;
	}
	if (izq) {
		arrayIteracion[contador] = tableroCopiaIzq;
		contador++;
	}
	return arrayIteracion.ObtenerIterador();
}
	

Matriz<int> Tablero::ObtenerTablero() const
{
	return elTablero;
}

Cadena Tablero::Imprimir() const
{
	string retorno = "";
	int l = elTablero.ObtenerAncho();
	for (int i = 0; i < l; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			retorno = retorno + std::to_string(elTablero[i][j - 1]);
			if (j % l == 0 && i < l - 1)
				retorno=retorno + "\n";
			else
				retorno =retorno + "-";
		}
	}
	return Cadena(retorno.c_str());
}


#endif