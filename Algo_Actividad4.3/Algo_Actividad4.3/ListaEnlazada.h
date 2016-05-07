#pragma once
#include "Nodo.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

class ListaEnlazada
{
private:
	Nodo* lista;
	int n; //  Número actual de elementos en la lista
	Nodo* getNodo(int posicion);
public:
	ListaEnlazada();
	~ListaEnlazada();
	int getValor(int posicion);
	void setValor(int posicion, int nuevoValor);
	int getN();
	void insertar(int posicion, int nuevoValor);
	void eliminar(int posicion);
};

