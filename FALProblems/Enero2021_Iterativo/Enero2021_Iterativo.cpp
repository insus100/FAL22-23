// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const&v, int const &n) {
    if (n == 1 || n == 2)
        return n;
    int sol = 2, primer_max = v[0], segundo_max = v[1];
    for (int i = 2; i < v.size(); i++) {
        int media = (primer_max + segundo_max) / 2;
        if (v[i] <= media) {
            sol++;
        }
        if (primer_max > segundo_max) {
            if (v[i] > segundo_max) {
                segundo_max = v[i];
            }
        }
        else {
            if (v[i] > primer_max) {
                primer_max = v[i];
            }
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& v : p)
        cin >> v;

    int sol = resolver(p, n);
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