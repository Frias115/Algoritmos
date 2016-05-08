#include "TablaHashDeEstudiantes.h"


int TablaHashDeEstudiantes::obtenerPosicion(int numeroMatricula)
{
	return (numeroMatricula % this->capacidad);
}

int TablaHashDeEstudiantes::buscarEstudiante(int numeroMatricula)
{
	int aux = this->obtenerPosicion(numeroMatricula);
	int casillasPorComprobar = this->capacidad;
	do {
		if (this->lista[aux].numeroMatricula == numeroMatricula) {
			return aux;
		}
		aux = (aux + 1) % this->capacidad;
		casillasPorComprobar--;
	} while (casillasPorComprobar > 0 || this->lista[aux].ocupado != false && this->lista[aux].borrado != false);

	return -1;
}

bool TablaHashDeEstudiantes::comprobarEstudiante(int numeroMatricula)
{
	if (this->buscarEstudiante(numeroMatricula) != -1) {
		return true;
	}
	return false;
}

string TablaHashDeEstudiantes::obtenerEstudiante(int numeroMatricula)
{
	assert(this->comprobarEstudiante(numeroMatricula) == true);

	return this->lista[this->buscarEstudiante(numeroMatricula)].nombreEstudiante;

}

void TablaHashDeEstudiantes::introducirEstudiante(int numeroMatricula, string nombreEstudiante)
{
	assert(!this->isLlena());
	assert(!this->comprobarEstudiante(numeroMatricula));

	int aux = this->buscarHueco(numeroMatricula);

	this->lista[aux].nombreEstudiante = nombreEstudiante;

	this->lista[aux].numeroMatricula = numeroMatricula;

	this->lista[aux].borrado = false;

	this->lista[aux].ocupado = true;

	this->capacidadLibreActual--;

}

void TablaHashDeEstudiantes::eliminarEstudiante(int numeroMatricula)
{
	assert(comprobarEstudiante(numeroMatricula));

	int aux = this->buscarEstudiante(numeroMatricula);

	this->lista[aux].ocupado = false;

	this->lista[aux].borrado = true;

	this->capacidadLibreActual++;

}

void TablaHashDeEstudiantes::imprimirTabla()
{
	assert(this->capacidad > 0);

	for (int i = 0; i < this->capacidad; i++) {
		cout << "Posicion: " << i << " | Llena: " << this->lista[i].ocupado << " | Borrada: " << this->lista[i].borrado << " | Clave: " << this->lista[i].numeroMatricula << " | Contenido: " << this->lista[i].nombreEstudiante << endl;
	}

}

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad)
{
	assert(capacidad > 0);
	this->capacidad = capacidad;
	this->capacidadLibreActual = capacidad;
	this->lista = new Elemento[capacidad];
}


TablaHashDeEstudiantes::~TablaHashDeEstudiantes()
{
	delete[] lista;
}

bool TablaHashDeEstudiantes::isLlena()
{
	if (this->capacidadLibreActual == 0) {
		return true;
	}
	return false;
}

int TablaHashDeEstudiantes::buscarHueco(int numeroMatricula)
{
	assert(!isLlena());
	int aux = this->obtenerPosicion(numeroMatricula);

	while (this->lista[aux].ocupado == true) {
		aux = (aux + 1) % this->capacidad;
	}

	return aux;
}
