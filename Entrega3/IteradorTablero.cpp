#ifndef ITERADORTABLERO_CPP
#define ITERADORTABLERO_CPP

#include "IteradorTablero.h"
#include "Tablero.h"

//Poscondicion: construye el iterador a la NodoTablero
template <class T>
IteradorTablero<T>::IteradorTablero(const Puntero<NodoTablero>& iterable) {
	this->inicio = iterable;
	this->listaL = iterable;
}
//Poscondicion: devuelve true si la NodoTablero tiene algun elemento. False en el caso contrario
template <class T>
bool IteradorTablero<T>::HayElemento() const {
	if (this->listaL != nullptr) {
		return true;
	}
	else {
		return false;
	}
}
//Precondicion: La NodoTablero no esta vacia
//Poscondicion: devuelve el dato en la posicion actual
template <class T>
const T& IteradorTablero<T>::ElementoActual() const {
	return this->listaL->dato;
}
//Precondicion: La NodoTablero no esta vacia
//Poscondicion: avanza en la NodoTablero
template <class T>
void IteradorTablero<T>::Avanzar() {
	this->listaL = this->listaL->padre;
}
//Pre: -
//Poscondicion: Reinicia el iterador a la posicion primera
template <class T>
void IteradorTablero<T>::Reiniciar() {
	this->listaL = this->inicio;
}
//Pre: -
//Poscondicion: clona el iterador
template <class T>
Puntero<Iteracion<T>> IteradorTablero<T>::Clonar() const {
	return nullptr;
}

#endif