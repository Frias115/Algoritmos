#include <iostream>
#include <cassert>
using namespace std;

int multiplicacionALaRusa(int operandoA, int operandoB);

void main() {
	int operando1, operando2, resultado;

	cout << "Introduce dos numeros mayores o iguales que 1: ";
	cin >> operando1 >> operando2;

	resultado = multiplicacionALaRusa(operando1, operando2);

	cout << "El resultado es: " << resultado << endl;
}

int multiplicacionALaRusa(int operandoA, int operandoB) {
	assert(operandoA >= 1);
	assert(operandoB >= 1);

	int resultado = 0;

	if (operandoA % 2 != 0) {
		resultado = operandoB;
	}

	operandoA = operandoA / 2;
	operandoB = operandoB * 2;

	if (operandoA >= 1)
	{
		resultado += multiplicacionALaRusa(operandoA, operandoB);
	}

	return resultado;
}