// Nombre del alumno Javier Gil Caballero, Íñigo Velasco Sánchez
// Usuario del Juez F32, F70

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

/*Coste en el caso peor: O(N) siendo N el numero de elementos que hay en el vector, ya que si lo recorremos de atras a delante y no se cumple la condición dada, se recorren
las N posiciones del vector con operaciones de coste O(1)*/

/*
Pre:{0 ≤ i < N}

fun resolver(vect numeros) dev (bool cumple)

Post:{cumple=(Ek: 0<=k<N: v[k] = suma)
suma:(Ei: 0<=i<N: v[i - 1] = Σi: 0<=i<N:v[i])}
*/

//Invariante: {0≤i<N /\ suma=(Ej: 0<=j<N: v[j - 1] = Σj: j<=i<N:v[i]) /\ cumple=(Ek: i<=k<N: v[k] = suma)}
//funcion de cota : i

// función que resuelve el problema
bool resolver(vector<int>const& numeros) {

	int i = numeros.size() - 1, suma = 0;
	bool cumple = false;
	while (i > -1 && !cumple) {
		if (suma == numeros[i]) {
			cumple = true;
		}
		suma += numeros[i];
		i--;
	}
	return cumple;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, num;
	cin >> n;
	if (n == 0)
		return false;
	vector<int> numeros;
	for (int i = 0; i < n; i++) {
		cin >> num;
		numeros.push_back(num);
	}
	bool sol = resolver(numeros);

	// escribir sol
	if (sol) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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