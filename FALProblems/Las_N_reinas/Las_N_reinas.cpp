// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
//using Matriz = vector<vector<bool>>;
// función que resuelve el problema
int diag_asc(const int x, const int y) {
	return x + y;
}

int diag_desc(const int x, const int y, const int n) {
	return (x - y + (n - 1));
}

bool no_ataca(vector<int> const& sol, const int k, const int n, vector<bool> const& filas, vector<bool> const& d_asc, vector<bool> const& d_desc) {
	return (!filas[sol[k]] && !d_asc[diag_asc(k, sol[k])] && !d_desc[diag_desc(k, sol[k], n)]);
}

bool es_solucion(vector<int> const& sol, const int k, const int n, vector<bool> const& filas, vector<bool> const& d_asc, vector<bool> const& d_desc) {
	return (k == n - 1) && no_ataca(sol, k, n, filas, d_asc, d_desc);
}

bool es_completable(vector<int> const& sol, const int k, const int n, vector<bool> const& filas, vector<bool> const& d_asc, vector<bool> const& d_desc) {
	return (k < n - 1) && no_ataca(sol, k, n, filas, d_asc, d_desc);
}

void procesar_solucion(int& num_sol) {
	num_sol++;
}

void n_reinas(vector<int>& sol, const int k, const int n, vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc, int& num_sol) {
	for (int i = 0; i < n; i++) {
		sol[k] = i;
		if (es_solucion(sol, k, n, filas, d_asc, d_desc)) {
			procesar_solucion(num_sol);
		}
		else if (es_completable(sol, k, n, filas, d_asc, d_desc)) {
			//marcamos
			filas[i] = true;
			d_asc[diag_asc(k, i)] = true;
			d_desc[diag_desc(k, i, n)] = true;
			//llamada recursiva
			n_reinas(sol, k + 1, n, filas, d_asc, d_desc, num_sol);
			//desmarcar
			filas[i] = false;
			d_asc[diag_asc(k, i)] = false;
			d_desc[diag_desc(k, i, n)] = false;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int N;
	cin >> N;
	int k = 0, num_sol = 0;
	//Matriz m(N, vector<bool>(N, false));
	vector<int> sol(N);
	vector<bool> filas(N);
	vector<bool> d_asc(2 * N - 1);
	vector<bool> d_desc(2 * N - 1);

	n_reinas(sol, k, N, filas, d_asc, d_desc, num_sol);
	cout << num_sol << "\n";
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