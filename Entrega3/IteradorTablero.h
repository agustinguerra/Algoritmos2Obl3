#pragma once

#include "Iterador.h"
#include "NodoTablero.h"

template <class T>
class IteradorTablero : public Iteracion<T> {
public:
	//Poscondicion: destruye la NodoTablero
	~IteradorTablero() {}
	//Poscondicion: construye el iterador a la NodoTablero
	IteradorTablero(const Puntero<NodoTablero>& iterable);
	//Poscondicion: devuelve true si la NodoTablero tiene algun elemento. False en el caso contrario
	bool HayElemento() const override;
	//Precondicion: La NodoTablero no esta vacia
	//Poscondicion: devuelve el dato en la posicion actual
	const T& ElementoActual() const override;
	//Precondicion: La NodoTablero no esta vacia
	//Poscondicion: avanza en la NodoTablero
	void Avanzar() override;
	//Pre: -
	//Poscondicion: Reinicia el iterador a la posicion primera
	void Reiniciar() override;
	//Pre: -
	//Poscondicion: clona el iterador
	Puntero<Iteracion<T>> Clonar() const  override;


private:
	Puntero<NodoTablero> inicio;
	Puntero<NodoTablero> listaL;
	int cantidadActual;
};


#include "IteradorTablero.cpp"