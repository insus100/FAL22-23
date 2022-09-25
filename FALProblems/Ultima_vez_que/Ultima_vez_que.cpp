// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(const vector<string> &nacionalidades, const string &ganador, const int &N) {
    int ultima_victoria = 0;
    for (int i = N - 1; i > -1; --i) {
        if (nacionalidades[i] != ganador)
            ultima_victoria++;
        else break;
    }
    if (ultima_victoria == N)
        return -1;
    else
        return ultima_victoria + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;
    string ganador;
    cin >> ganador;

    vector<string> nacionalidades(N);
    for (int i = 0; i < N; ++i) {
        cin >> nacionalidades[i];
    }
    
    int sol = resolver(nacionalidades, ganador, N);

    // escribir sol
    sol == -1 ? cout << "NUNCA" : cout << sol;
    cout << "\n";
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
