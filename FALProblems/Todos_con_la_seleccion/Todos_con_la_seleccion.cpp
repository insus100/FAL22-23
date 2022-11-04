// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct Sol {
    int max_ganados;
    int veces;
    int jugados;
};

// función que resuelve el problema
Sol resolver(vector<int> const &v) {
    Sol sol{ 0, 0, 0 };
    int ganados = 0;
    for (int i = 0; i < v.size(); i++) {
        sol.jugados++;
        if(v[i] > 0) {//ganado
            ganados++;
        }
        else {
            if (ganados > 0) {
                if (sol.max_ganados == ganados) {
                    sol.veces++;
                    sol.jugados = 1;
                }
                else if(ganados > sol.max_ganados) {
                    sol.max_ganados = ganados;
                    sol.veces = 1;
                    sol.jugados = 1;
                }
                ganados = 0;
            }
        }
    }
    if (ganados > sol.max_ganados) {
        sol.max_ganados = ganados;
        sol.veces = 1;
        sol.jugados = 0;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<int> goles(n);
    for (int& g : goles)
        cin >> g;

    Sol sol = resolver(goles);

    // escribir sol
    cout << sol.max_ganados << " " << sol.veces << " " << sol.jugados << "\n";

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