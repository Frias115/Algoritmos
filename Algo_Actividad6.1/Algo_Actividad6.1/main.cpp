#pragma once
#include "TablaHashDeEstudiantes.h"

void main() {
	int capacidad; // Capacidad de la tabla hash

	//Variables que uso en el menu para manejar la tabla hash
	int opcion, numeroEstudiante; 
	bool check;
	string nombreEstudiante;

	//Pido la capacidad de la tabla hash
	do {
		cout << "Introduce la capacidad de la tabla: ";
		cin >> capacidad;
	} while (capacidad <= 0);

	//Creo la tabla hash con la capacidad que me han pedido
	TablaHashDeEstudiantes tabla(capacidad);

	//Se inicia el menu para manejar la tabla hash
	do {
		cout << "0. Salir" << endl;
		cout << "1. Imprimir tabla" << endl;
		cout << "2. Comprobar si esta un estudiante" << endl;
		cout << "3. Ver un estudiante" << endl;
		cout << "4. Meter un estudiante" << endl;
		cout << "5. Eliminar un estudiante" << endl;
		cout << "Introduzca opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 0:
			cout << "Adios" << endl;
			break;

		case 1:
			tabla.imprimirTabla();
			break;

		case 2:
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> numeroEstudiante;

			check = tabla.comprobarEstudiante(numeroEstudiante);

			if (check) {
				cout << "El estudiante esta" << endl;
			}
			else {
				cout << "El estudiante NO esta" << endl;
			}

			break;

		case 3:
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> numeroEstudiante;

			cout << "El estudiante se llama " << tabla.obtenerEstudiante(numeroEstudiante) << endl;

			break;

		case 4:
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> numeroEstudiante;
			cout << "Introduzca el nombre del estudiante: ";
			cin >> nombreEstudiante;

			tabla.introducirEstudiante(numeroEstudiante, nombreEstudiante);

			break;

		case 5:
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> numeroEstudiante;

			tabla.eliminarEstudiante(numeroEstudiante);

			break;

		default:
			cout << "Opcion no valida" << endl;
			break;
		}

	} while (opcion != 0);


}