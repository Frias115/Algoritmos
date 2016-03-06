#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

struct SolucionParcial
{
public:
	float x;
	float y;
};

class Polinomio
{
public:
	Polinomio(int nuevoGrado, float *nuevosCoeficientes);
	~Polinomio();
	float evaluar(float numeroAEvaluar);
	float obtenerMaximo();
	float obtenerMaximo(SolucionParcial padre);

private:

	int grado;
	float *coeficientes;
};

