// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using par = pair<int, int>;
struct Sol {
    int max;
    int no_mejora;
    int ini;
    int fin;
};
// función que resuelve el problema
Sol resolver(vector<int> const &marcas) {//O(n)
    Sol sol{0,0,0,0};
    int no_mejora = 0;
    par intervalo{0, 0};
    bool segmento = false;
    for (int i = 0; i < marcas.size(); i++) {
        if (marcas[i] > sol.max) {
            sol.max = marcas[i];
            segmento = false;
            if (intervalo.second - intervalo.first >= sol.fin - sol.ini) {
                sol.ini = intervalo.first;
                sol.fin = intervalo.second;
            }
            if (no_mejora > sol.no_mejora) sol.no_mejora = no_mejora;
            no_mejora = 0;
        }
        else {
            no_mejora++;
            if (!segmento) {
                intervalo.first = i;
                segmento = true;
            }
            else intervalo.second = i;
        }
    }
    if (no_mejora > 0 && sol.no_mejora == 0)
        sol.no_mejora = no_mejora;
    if (intervalo.second - intervalo.first > sol.fin - sol.ini) {
        sol.ini = intervalo.first;
        sol.fin = intervalo.second;
    }
    if (intervalo.first == 0 && sol.ini == 0) sol.ini = marcas.size();
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    vector<int> marcas(n);
    for (int &m : marcas) {
        cin >> m;
    }
    Sol sol = resolver(marcas);

    // escribir sol
    cout << sol.no_mejora << " " << sol.ini << "\n";

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
