#include "ListaEnlazada.h"


void ListaEnlazada::setValor(int posicion, int nuevoValor) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n - 1);
	this->getNodo(posicion)->elemento = nuevoValor;
}

int ListaEnlazada::getValor(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n - 1);
	return (this->getNodo(posicion)->elemento);
}

int ListaEnlazada::getN() {
	return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	

	Nodo * nuevoNodo = new Nodo;
	//Caso lista vacia
	if (n == 0) {
		lista = nuevoNodo;
		lista->elemento = nuevoValor;
		n++;
	}
	//Caso normal
	else if (posicion != 0 && posicion < n) {
		
		nuevoNodo->siguienteNodo = getNodo(posicion);
		nuevoNodo->elemento = nuevoValor;
		getNodo(posicion - 1)->siguienteNodo = nuevoNodo;
		n++;
	}
	//Caso insertar en inicio
	else if (posicion == 0) {

		nuevoNodo->siguienteNodo = getNodo(posicion);
		nuevoNodo->elemento = nuevoValor;
		lista = nuevoNodo;
		n++;
	}
	//Caso insertar al final
	else if (posicion == n) {

		nuevoNodo->siguienteNodo = NULL;
		nuevoNodo->elemento = nuevoValor;

		getNodo(posicion - 1)->siguienteNodo = nuevoNodo;
		n++;
	}
}

void ListaEnlazada::eliminar(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1);

	Nodo * aux = new Nodo;
	//Caso normal
	if (posicion != 0 && posicion < n - 1 && n > 0) {
		aux = getNodo(posicion + 1);
		delete getNodo(posicion);
		getNodo(posicion - 1)->siguienteNodo = aux;
		n--;
	}
	//Caso eliminar en inicio
	else if (posicion == 0 && n > 0) {
		aux = getNodo(posicion + 1);
		delete getNodo(posicion);
		lista = aux;
		n--;
	}
	//Caso eliminar al final
	else if (posicion == n - 1) {
		getNodo(posicion - 1)->siguienteNodo = NULL;
		delete getNodo(posicion);
		n--;
	}
}


Nodo * ListaEnlazada::getNodo(int posicion)
{
	assert(posicion >= 0 && posicion <= n);
	Nodo * result = this->lista;

	if (posicion == 0) {
		return result;
	}
	else {
		for (int i = 0; i < posicion; i++) {
			result = result->siguienteNodo;
		}
	}
	
	return result;
}

ListaEnlazada::ListaEnlazada()
{
	n = 0;
	lista = NULL;
}


ListaEnlazada::~ListaEnlazada()
{
	for (int i = 0; i < n;) {
		eliminar(i);
	}
}
