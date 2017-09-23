#ifndef SISTEMATEMPLATES_CPP
#define SISTEMATEMPLATES_CPP

#include "Sistema.h"
#include "ColaPrioridadExtendidaImp.h"
template <class T, class P>
Puntero<ColaPrioridadExtendida<T, P>> Sistema::CrearColaPrioridadExtendida(const Comparador<T>& compElementos, const Comparador<P>& compPrioridades, Puntero<FuncionHash<T>> fHashElementos) {
	Puntero<ColaPrioridadExtendida<T, P>> cp = new ColaPrioridadExtendidaImp<T, P>(fHashElementos,compElementos,compPrioridades);
	return cp;
}

#endif