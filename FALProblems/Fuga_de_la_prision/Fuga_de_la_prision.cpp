// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
char resolver(vector<char> const& v, int const& ini, int const& fin, char const& x1, char const& x2) {
	if (ini + 1 == fin) {
		if (v[ini] == x1)
			return x2;
		else return x1;
	}
	else {
		int m = (ini + fin) / 2;
		char medio = (x1 + x2) / 2;
		if (v[m] > medio) {
			return resolver(v, ini, m, x1, medio);
		}else{
			return resolver(v, m, fin, medio, x2);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char x1, x2;
	cin >> x1 >> x2;
	int n = x2 - x1;
	vector<char> v(n);
	for (int i = 0; i < n;i++) {
		cin >> v[i];
	}

	char sol = resolver(v, 0, n, x1, x2);
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