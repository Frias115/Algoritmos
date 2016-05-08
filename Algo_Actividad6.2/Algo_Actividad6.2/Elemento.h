#pragma once
#include <iostream> // cout, cin, bool
#include <string> // string
using namespace std;

//Estructura de la que se componen los elementos de la tabla hash de estudiantes
struct Elemento
{
	int numeroMatricula; //Numero de la matricula del estudiante
	string nombreEstudiante; //Nombre del estudiante
	bool ocupado = false; //Bit para comprobar si la posicion esta ocupada o no
	bool borrado = false; //Bit para comprobar si la posicion a sido borrada o no
};