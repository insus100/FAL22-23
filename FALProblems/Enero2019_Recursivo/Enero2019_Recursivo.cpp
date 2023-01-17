// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void resolver(int n, int& suma, int& cont, bool& sol) {
	int digito = n % 10;
	if (n > 0) {
		resolver(n / 10, suma, cont, sol);
		suma += digito;
		cont++;
		if (!((suma % cont) == 0)) {
			sol = false;
			suma -= digito;
		}
	}

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, suma = 0, cont = 0;
	cin >> n;
	if (n == 0)
		return false;

	bool sol = true;
	resolver(n, suma, cont, sol);
	// escribir sol
	sol ? cout << "SI" : cout << "NO";
	cout << "\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
