#include "Polinomio.h"


void main() {
	int gradoPolinomio;
	float *coeficientesPolinomio;
	float resultado;
	
	srand(time(NULL));

	cout << "Introduce el grado del polinomio (mayor o igual que 0): ";
	cin >> gradoPolinomio;

	coeficientesPolinomio = (float*)malloc(sizeof(float)*(gradoPolinomio+1));

	cout << gradoPolinomio + 1 << " coeficientes, separados por espacios y ordenados de grado menor a mayor:";
	for (int i = 0; i <= gradoPolinomio; i++) {
		cin >> coeficientesPolinomio[i];
	}
	Polinomio polinomio(gradoPolinomio, coeficientesPolinomio);

	for (int i = 0; i < 10; i++) {
		resultado = polinomio.obtenerMaximo();
		cout << endl;
		cout << "Maximo resultado de la ejecucion numero " << i << ": " << resultado << endl << endl;
	}

	free(coeficientesPolinomio);
}