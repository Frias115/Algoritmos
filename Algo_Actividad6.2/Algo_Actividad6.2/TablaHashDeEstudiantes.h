#pragma once
#pragma once
#include "Elemento.h"
#include <assert.h> // assert()

//Clase de las tablas Hash de estudiantes
class TablaHashDeEstudiantes
{
private:
	int capacidad; //La capacidad de la tabla Hash. No se modifica a lo largo de su vida

	int capacidadLibreActual;
	
	Elemento *lista; //Array de Elemento que conforma la tabla Hash

	//Funcion Hash que nos devuelve la posicion real dentro de la tabla Hash de un elemento que le pasemos
	//Variables: numeroMatricula: entero que utilizamos para indicar el numero al que queremos hacer el hash
	//Retorno: numero tras pasar por la funcion de hash (numeroMatricula % capacidad)
	//Precondiciones: numeroMatricula > 0
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	int obtenerPosicion(int numeroMatricula);

	int buscarEstudiante(int numeroMatricula);


public:
	//Comprueba si un estudiante con un numero de matricula concreto esta o no en la tabla hash
	//Variables: numeroMatricula: entero que utilizamos para buscar al estudiante dentro de la tabla hash
	//Retorno: booleano que nos indica si existe o no un estudiante con ese numero de matricula
	//Precondiciones: numeroMatricula > 0
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	bool comprobarEstudiante(int numeroMatricula);

	//Recibimos el nombre del estudiante que tiene el numero de matricula que le hemos pasado
	//Variables: numeroMatricula: entero que utilizamos para buscar al estudiante dentro de la tabla hash
	//Retorno: nombre del estudiante que tiene ese numero de matricula
	//Precondiciones: comprobarEstudiante(numeroMatricula) == true
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	string obtenerEstudiante(int numeroMatricula);

	//Introducimos un estudiante nuevo a la tabla para ello le damos un numero de matricual y un nombre
	//Variables: numeroMatricula: entero del numero de matricula del estudiante que vamos a introducir
	//           nombreEstudiante: string que es el nombre del estudiante que vamos a introducir
	//Precondiciones: lista[obtenerPosicion(numeroMatricula)].ocupado == false
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	void introducirEstudiante(int numeroMatricula, string nombreEstudiante);

	//Elimina un estudiante que tenga el numero de matricula que introducimos de la tabla
	//Variables: numeroMatricula: entero del numero de matricula del estudiante que vamos a eliminar
	//Precondiciones: this->lista[this->obtenerPosicion(numeroMatricula)].ocupado == true
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	void eliminarEstudiante(int numeroMatricula);

	//Imprimimos la tabla hash completa, esto viola el principio de separación entre modelo e interfaz
	//Precondiciones: capacidad > 0
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(capacidad)
	void imprimirTabla();

	//Constructor al que le pasamos la capacidad de la tabla hash que vamos a utilizar
	//Variables: capacidad: entero que representa el tamaño que queremos que tenga nuestra tabla hash
	//Precondiciones: capacidad > 0
	//Complejidad espacial: O(capacidad)
	//Complejidad temporal: O(capacidad)
	TablaHashDeEstudiantes(int capacidad);

	//Destructor en el que liberamos la memoria que hemos reservado en el constructor para la tabla hash
	//Complejidad espacial: O(1)
	//Complejidad temporal: O(1)
	~TablaHashDeEstudiantes();

	bool isLlena();

	int buscarHueco(int numeroMatricula);
	
};

