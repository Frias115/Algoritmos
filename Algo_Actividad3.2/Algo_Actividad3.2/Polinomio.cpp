#include "Polinomio.h"

Polinomio::Polinomio(int nuevoGrado, float *nuevosCoeficientes)
{
	this->coeficientes = (float*)malloc(sizeof(float) * (nuevoGrado + 1));

	for (int i = 0; i <= nuevoGrado; i++) {
		this->coeficientes[i] = nuevosCoeficientes[i];
	}

	this->grado = nuevoGrado;
}

Polinomio::~Polinomio()
{
	//free(this->coeficientes);
}

float Polinomio::evaluar(float numeroAEvaluar) {
	float resultado = 0;
	for (int i = 0; i < this->grado + 1; i++) {
		resultado += this->coeficientes[i] * (pow(numeroAEvaluar, i));
	}
	return resultado;
}



float Polinomio::obtenerMaximo() {
	
	SolucionParcial solucionInicial;
	solucionInicial.x = 0;
	solucionInicial.y = evaluar(solucionInicial.x);

	printf("(%.1f,%.1f): ", solucionInicial.x, solucionInicial.y);

	float mejorSolucion = solucionInicial.x;
	float mutacion = 0;
	int numeroHijos;

	numeroHijos = rand() % 3 + 3;
	
	for (int j = 0; j < numeroHijos; j++) {
		
		SolucionParcial solucionAProbar;
		solucionAProbar.x = 0;

		for (int i = 0; i < 12; i++) {
			mutacion += (rand() / (float)RAND_MAX);
		}
		mutacion -= 6;

		solucionAProbar.x = solucionInicial.x + mutacion;
		solucionAProbar.y = evaluar(solucionAProbar.x);
		if (solucionAProbar.y > solucionInicial.y) {
			mejorSolucion = solucionAProbar.x;
		}

		mutacion = 0;
	}

	

	if (mejorSolucion != solucionInicial.x) {
		SolucionParcial mejorHijo;
		mejorHijo.x = mejorSolucion;
		mejorHijo.y = evaluar(mejorHijo.x);
		printf("(%.1f,%.1f), ", mejorHijo.x, mejorHijo.y);
		mejorSolucion = obtenerMaximo(mejorHijo);
	}

	return mejorSolucion;
}

float Polinomio::obtenerMaximo(SolucionParcial padre) {

	float mejorSolucion = padre.x;
	float mutacion = 0;
	int numeroHijos;

	numeroHijos = rand() % 5 + 3;

	for (int j = 0; j < numeroHijos; j++) {

		SolucionParcial hijo;
		hijo.x = 0;

		for (int i = 0; i < 12; i++) {
			mutacion += (rand() / (float)RAND_MAX);
		}
		mutacion -= 6;

		hijo.x = padre.x + mutacion;
		hijo.y = evaluar(hijo.x);

		if (hijo.y > padre.y) {
			mejorSolucion = hijo.x;
		}
		mutacion = 0;
	}

	if (mejorSolucion != padre.x) {
		SolucionParcial mejorHijo;
		mejorHijo.x = mejorSolucion;
		mejorHijo.y = evaluar(mejorHijo.x);
		printf("(%.1f,%.1f), ", mejorHijo.x, mejorHijo.y);
		mejorSolucion = obtenerMaximo(mejorHijo);
	}

	return mejorSolucion;

}