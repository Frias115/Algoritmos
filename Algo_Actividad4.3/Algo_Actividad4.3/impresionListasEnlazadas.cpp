#include "impresionListasEnlazadas.h"

void imprimirListaEnlazada(ListaEnlazada * lista)
{
	assert(lista != NULL);

	// Imprimimos tamaño 
	cout << "n=" << lista->getN() << "|ListaEnlazada= ";

	// Si la ListaEnlazada está vacía, imprimimos algo especial
	if (lista->getN() == 0) cout << "vacia";

	// Si no está vacía, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (lista->getN() > 20) cout << "demasiadosElementosParaMostrar";
		else {
			for (int i = 0; i < lista->getN(); i++) {
				cout << lista->getValor(i);
				if (i < lista->getN() - 1) cout << ","; // Imprimimos "," si no estamos al final
			}
		}
	}
	cout << endl;
}
