#pragma once
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"

void main() {

	ListaEnlazada * lista = new ListaEnlazada;

	cout << "Nueva ListaEnlazada creada: " << endl;

	imprimirListaEnlazada(lista);

	cout << "Inserto 10 con la lista vacia: " << endl;

	lista->insertar(0,10);

	imprimirListaEnlazada(lista);

	cout << "Inserto 20 y 21 al final: " << endl;

	lista->insertar(1,20);

	lista->insertar(2, 21);

	imprimirListaEnlazada(lista);

	cout << "Inserto 30 al principio: " << endl;

	lista->insertar(0, 30);

	imprimirListaEnlazada(lista);

	cout << "Inserto 40 en la posicion 2: " << endl;

	lista->insertar(2, 40);

	imprimirListaEnlazada(lista);

	cout << "Elimino el primer elemento: " << endl;

	lista->eliminar(0);

	imprimirListaEnlazada(lista);

	cout << "Elimino el ultimo elemento: " << endl;

	lista->eliminar(3);

	imprimirListaEnlazada(lista);

	cout << "Elimino el elemento del medio: " << endl;

	lista->eliminar(1);

	imprimirListaEnlazada(lista);

	cout << "Elimino el 20 y el 10 para dejar la lista vacia: " << endl;

	lista->eliminar(1);

	imprimirListaEnlazada(lista);

	lista->eliminar(0);

	imprimirListaEnlazada(lista);

	cout << "Vuelvo a repetir las insercciones del principio: " << endl;

	cout << "Inserto 10 con la lista vacia: " << endl;

	lista->insertar(0, 10);

	imprimirListaEnlazada(lista);

	cout << "Inserto 20 y 21 al final: " << endl;

	lista->insertar(1, 20);

	lista->insertar(2, 21);

	imprimirListaEnlazada(lista);

	cout << "Inserto 30 al principio: " << endl;

	lista->insertar(0, 30);

	imprimirListaEnlazada(lista);

	cout << "Inserto 40 en la posicion 2: " << endl;

	lista->insertar(2, 40);

	imprimirListaEnlazada(lista);


}