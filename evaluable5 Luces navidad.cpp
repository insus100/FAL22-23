/*
 * Nombre y usuarios de la pareja:
 * Ignacio Fluxá Casas F25
 * Begoña Pascual Goenechea F53
 *
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


bool esValida(const vector <int>& v, const vector<int>& tira, const vector <int>& marca, int i, int bombillas, int max_consumo, int consumo) {
	int mi_color = marca[i];
	int resto_colores = bombillas - mi_color;

	if ((mi_color - resto_colores) > 0) { return false; } // Comprobaciones de luces
	if (max_consumo < (consumo + v[i])) { return false; } 

	if ((bombillas >= 2) && (tira[bombillas - 2] == i) && (tira[bombillas - 1] == i)) {
		return false;  // Comprobamos el numero de bombillas iguales, si son mas de dos no ponemos la tercera.
	}
	return true;

}


void navidad(const vector <int>& v, vector<int>& tira, vector <int>& marca, int longi, int colores, int max_consumo, int& permutaciones, int bombillas, int consumo) {
	int i = 0;

	while (i < colores) {
		tira[bombillas] = i;

		if (esValida(v, tira, marca, i, bombillas, max_consumo, consumo)) { // comprobacion de si es valida 
			++marca[i];
			if (longi == (bombillas + 1)) {
				++permutaciones;
			}
			else {
				navidad(v, tira, marca, longi, colores, max_consumo, permutaciones, bombillas + 1, consumo + v[i]);
			}
			--marca[i];
		}
		++i;
	}

}

bool resuelveCaso() {
	int longi, colores, max_consumo, permutaciones;
	vector <int> v_costes; 
	vector <int> marca;
	vector <int> tira; 

	cin >> longi;

	if (longi == 0) { return false; }
	cin >> colores >> max_consumo;

	v_costes.resize(colores);
	for (int i = 0; i < colores; ++i) {
		cin >> v_costes[i];
	}
	permutaciones = 0;
	marca.resize(colores);
	tira.resize(longi);

	navidad(v_costes, tira, marca, longi, colores, max_consumo, permutaciones, 0, 0);

	cout << permutaciones << "\n";
	return true;


}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {

	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif

	return 0;
}