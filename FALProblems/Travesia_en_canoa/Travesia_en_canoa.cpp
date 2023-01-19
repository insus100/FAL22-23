// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using Matriz = vector<vector<int>>;
// función que resuelve el problema

bool valida(const int k, int const& peso_canoa, vector<int> const& personas_canoa, vector<bool>& usos, const int P, Matriz const& m) {
    if (peso_canoa > P) return false;
    if (personas_canoa[k] > 3) return false;

    //if (m[i][j] == 1) return false;//mirar si estan enemistados
    return true;
}

void resolver(vector<int> &sol, int &peso_canoa, vector<int> &personas_canoa, const int k, vector<bool>&usos, vector<int> const &pesos, const int M, const int N, const int P, Matriz const & m, int& num_sol) {
    for (int persona = 0; persona < M; persona++) {
        if (!usos[persona]) {
            sol[k] = persona;
            peso_canoa += pesos[persona];
            personas_canoa[k]++;
            usos[persona] = true;
            if (valida(k, peso_canoa, personas_canoa, usos, P, m)) {
                if (M - 1 == k) num_sol++;
                else resolver(sol, peso_canoa, personas_canoa, k + 1, usos, pesos, M, N, P, m, num_sol);
            }
            peso_canoa -= pesos[persona];
            personas_canoa[k]--;
            usos[persona] = false;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int M, N, P;
    cin >> M >> N >> P;
    vector<int> pesos(M);
    vector<int> personas_canoa(N);
    vector<bool> usos(M);
    //int usos = 0;
    vector<int> sol(N);
    Matriz m(M, vector<int>(M, false));
    for (int i = 0; i < M; i++) {
        cin >> pesos[i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }

    int num_sol = 0,peso_canoa = 0;
    resolver(sol, peso_canoa, personas_canoa, 0, usos, pesos, M, N, P, m, num_sol);
    // escribir sol
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