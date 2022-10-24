// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
struct Sol {
    int suma;
    int ini;
    int fin;
    int dias;
};
using par = pair<int, int>;
// función que resuelve el problema
Sol resolver(vector<int> const &datos) {
    Sol sol{ 0,0,0,0 };
    int curSuma = 0;
    par curIntervalo{ 0, 0 };
    for (int i = 0; i < datos.size(); i++) {
        curSuma += datos[i];
        if (curSuma <= 0) {
            curSuma = 0;
            curIntervalo.first = i + 1;
        }
        else {
            curIntervalo.second = i;
            if(curSuma > sol.suma) {
                sol.suma = curSuma;
                sol.fin = i;
                sol.ini = curIntervalo.first;
            }
            else if(curSuma == sol.suma) {
                if (curIntervalo.second - curIntervalo.first < sol.fin - sol.ini) {
                    sol.ini = curIntervalo.first;
                    sol.fin = curIntervalo.second;
                }
            }
        }
    }
    sol.dias = sol.fin - sol.ini + 1;
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
    vector<int> pesos(n);
    for (int i = 0; i < n; i++) {
        cin >> pesos[i];
    }

    Sol sol = resolver(pesos);

    // escribir sol
    cout << sol.suma << " " << sol.ini << " " << sol.dias << "\n";
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