// Javier Gil Caballero F32
// Íñigo Velasco Sánchez F70
// Puesto 0918


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
/*
* La recursividad sería:
* T(n) =
* {
*   k1 para n = 0
*   T(n/2) + k2 para n > 0
* }
* siendo k1 y k2 constantes.
* El coste de la función resolver es O(logN) siendo N el tamaño del vector (el número de elementos
* que tiene el vector.)
*/
// función que resuelve el problema
int resolver(vector<int> const&v, int ini, int fin) {
    if (ini == fin) {
        if (v[ini] % 2 != 0) return v[ini];
    }
    else if (ini + 1 == fin) {
        if (v[ini] % 2 != 0) return v[ini];
        else if (v[fin] % 2 != 0) return v[fin];
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] % 2 != 0) return v[mitad];
        else if (v[mitad] == v[ini] + 2 * (mitad - ini)) {
            return resolver(v, mitad + 1, fin);//miramos por el segmento derecho
        }
        else {
            return resolver(v, ini, mitad);//mirar por el segmento izquierdo
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int sol = resolver(v, 0, n - 1);

    // escribir sol
    cout << sol << "\n";
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
