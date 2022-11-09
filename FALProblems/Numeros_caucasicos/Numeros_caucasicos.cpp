// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
/*
* T(n) = c                  n = 0, 1
* T(n) = 2T(n/2) + n        n > 1;
* coste O(nlog(n))
*/
// función que resuelve el problema
pair<int, bool> resolver(vector<int> const &v, int const &ini, int const &fin) {
    if (ini == fin) {
        return { 0, true };
    }
    else if (ini + 1 == fin) {
        if (v[ini] % 2 == 0 && v[fin] % 2 == 0) return { 2, true };
        else if (v[ini] % 2 == 0 || v[fin] % 2 == 0) return { 1, true };
        else return { 0 , true };
    }
    else {
        int mitad = (ini + fin) / 2;
        pair<int, bool> izq = resolver(v, ini, mitad);
        pair<int, bool> der = resolver(v, mitad + 1, fin);
        return { izq.first + der.first, abs(izq.first - der.first) <= 2 && izq.second && der.second };
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
    pair<int, bool> sol = resolver(v, 0, n-1);
    // escribir sol
    sol.second ? cout << "SI\n" : cout << "NO\n";
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
