#include "TablaHashDeEstudiantes.h"


int TablaHashDeEstudiantes::obtenerPosicion(int numeroMatricula)
{
	return (numeroMatricula % this->capacidad);
}

bool TablaHashDeEstudiantes::comprobarEstudiante(int numeroMatricula)
{
	if (this->lista[this->obtenerPosicion(numeroMatricula)].ocupado == true && this->lista[this->obtenerPosicion(numeroMatricula)].numeroMatricula == numeroMatricula) {
		return true;
	}
	return false;
}

string TablaHashDeEstudiantes::obtenerEstudiante(int numeroMatricula)
{
	assert(this->comprobarEstudiante(numeroMatricula) == true);
	
	return this->lista[this->obtenerPosicion(numeroMatricula)].nombreEstudiante;
}

void TablaHashDeEstudiantes::introducirEstudiante(int numeroMatricula, string nombreEstudiante)
{
	assert(this->lista[this->obtenerPosicion(numeroMatricula)].ocupado == false);

	this->lista[this->obtenerPosicion(numeroMatricula)].nombreEstudiante = nombreEstudiante;

	this->lista[this->obtenerPosicion(numeroMatricula)].numeroMatricula = numeroMatricula;

	this->lista[this->obtenerPosicion(numeroMatricula)].ocupado = true;

}

void TablaHashDeEstudiantes::eliminarEstudiante(int numeroMatricula)
{
	assert(this->lista[this->obtenerPosicion(numeroMatricula)].ocupado == true);

	this->lista[this->obtenerPosicion(numeroMatricula)].ocupado = false;

}

void TablaHashDeEstudiantes::imprimirTabla()
{
	assert(this->capacidad > 0);

	for (int i = 0; i < this->capacidad; i++) {
		cout << "Posicion: " << i << " | Flag: " << this->lista[i].ocupado << " | Clave: " << this->lista[i].numeroMatricula << " | Contenido: " << this->lista[i].nombreEstudiante << endl;
	}

}

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad)
{
	assert(capacidad > 0);
	this->capacidad = capacidad;
	this->lista = new Elemento[capacidad];
}


TablaHashDeEstudiantes::~TablaHashDeEstudiantes()
{
	delete[] lista;
}
