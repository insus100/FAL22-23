// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
// función que resuelve el problema

int resolver(int n1, int n2, int pot) {
	int sol1 = n1 % 10;
	int sol2 = n2 % 10;
	int sol = sol1 + sol2;
	if (n1 != 0 || n2 != 0) {
		if (sol > 9) {
			sol = sol % 10 * pot;
		}
		else sol = sol * pot;
		return resolver(n1 / 10, n2 / 10, pot * 10) + sol;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int N1, N2;
	cin >> N1 >> N2;

	int sol = resolver(N1, N2, 1);
	// escribir sol
	cout << sol << " " << sol << "\n";

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