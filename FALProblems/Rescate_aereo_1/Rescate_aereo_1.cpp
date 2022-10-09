// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int diferencia(pair<int, int> const& par) {
    return par.second - par.first;
}

// función que resuelve el problema
pair<int, int> resolver(vector<int> const &alturas, int const &n, int const &t) {
    //int i = 0, j = 1, interval_length = 0, interval_length_aux = 0;
    //bool interval_found = false;//solo se usa si el intervalo es de 1 elemento (ini == fin)
    int ini = -1, fin = -1;
    pair<int, int> sol(0, -1);
    for (int i = 0; i < n; i++) {
        if (alturas[i] > t) {
            if (ini == -1) {
                ini = i;
                fin = i;
            }
            else fin = i;

            if (fin - ini > sol.second - sol.first) {
                sol.first = ini;
                sol.second = fin;
            }
        }
        else ini = -1;
    }


    //no le da la gana funcionar al juez chinoso
    /*while (i < n && j < n) {
        if (alturas[i] <= t) {//checamos inicio del intervalo
            i++;
            j = i + 1;
        }
        else {//si el inicio es mayor que t, empezamos a mirar el final del intervalo
            if (alturas[j] > t) {
                j++;
                interval_length++;
                if (j == n && (interval_length_aux == 0 || interval_length > interval_length_aux)) {
                    sol.first = i;
                    sol.second = j - 1;
                }
            }
            else {
                if (interval_length_aux == 0 && !interval_found) {
                    sol.first = sol.second = i;
                    interval_found = true;
                }
                if (interval_length > interval_length_aux) {
                    sol.first = i;
                    sol.second = j - 1;
                }
                interval_length_aux = interval_length;
                interval_length = 0;
                i = j + 1;
                j = i + 1;
            }
        }
    }
    if(i == n - 1 && interval_length_aux == 0 && alturas[i] > t && !interval_found)//el mayor edificio es el último de la lista.
        sol.first = sol.second = i;*/

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n, t;
    cin >> n >> t;
    vector<int> alturas(n);

    for (int i = 0; i < n; i++) {
        cin >> alturas[i];
    }

    pair<int, int> sol = resolver(alturas, n, t);
    // escribir sol
    cout << sol.first << " " << sol.second << "\n";
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