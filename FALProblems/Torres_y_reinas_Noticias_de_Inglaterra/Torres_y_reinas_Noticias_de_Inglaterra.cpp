// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using Matriz = vector<vector<bool>>;

struct Casilla {
    bool torre;
    bool reina;
    bool rota;
};

// función que resuelve el problema
void resolver(Matriz const &m, int const k) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int T, R;
    cin >> T >> R;
    if (!std::cin)
        return false;
    int tam = T + R;
    Matriz m(tam + 1, vector<bool>(tam, false));//matriz que contiene las casillas rotas.
    int rotas, fila_r, columna_r;
    cin >> rotas;
    for (int i = 0; i < rotas; i++) {
        cin >> fila_r >> columna_r;
        m[fila_r][columna_r] = true;
    }
    vector<bool> filas = vector<bool>(tam, false); //para empezar en 1
    vector<bool> diagR = vector<bool>(4 * tam-2, false); // hay 4N -2 pero si empezamos en el 1 hay que sumar 2 más
    vector<bool> diagT = vector<bool>(4 * tam-2, false); // hay 4N -2 pero si empezamos en el 1 h
    resolver(m, 0, filas, diagR, diagT, m, );

    // escribir sol


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