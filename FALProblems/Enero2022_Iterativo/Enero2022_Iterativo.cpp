// NOMBRE Y APELLIDOS 

// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//ESPECIFICA la funcion que resuelve el problema

//PRECONDICION:

int resolver(vector<int> const& v) { 
	//INVARIANTE: 
	//F. COTA:
	int nPares = 0, i = 0, ini = 0;

	while (i < v.size()) {
		if (v[i] % 2 != 0)
			ini = i + 1;
		nPares += i - ini + 1;
		i++;
	}
	return nPares;
}

//POSTCONDICION:


// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	int numElems = 0;int k;
	cin >> numElems;
	vector<int> v(numElems);
	for (int& i : v) cin >> i;
	int sol = resolver(v);
	cout << sol << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("sample1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}
