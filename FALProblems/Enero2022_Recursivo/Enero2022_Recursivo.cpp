// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
void resolver(int n, int potencia, int &sol, int n2) {
	if (n < 10) {
		if (n == 0) sol = 0;
		sol = 1;
	}
	else {

		resolver(n / 10, potencia, sol,n2);
		potencia * 10;
		if (n == 0) {
			int digito1 = n % potencia;

		}

	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;

	int sol;
	resolver(n, 1, sol, n);
	// escribir sol
	cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}