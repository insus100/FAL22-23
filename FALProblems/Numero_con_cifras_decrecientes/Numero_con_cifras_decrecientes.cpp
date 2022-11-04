// Nombre del alumno
// Javier Gil Caballero F32 
// Íñigo Velasco Sánchez F70
// Puesto 0919


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
using namespace std;
/*
 * El coste es lineal O(n) siendo n el número de dígitos que tiene el entero de la entrada.
 * T(n) {
    c1 si 0 <= n < b //c1 es un coste constante.
    a * T(n/b) + c2 n^k si n >= b //b es la división entre 10 que hacemos en la llamada recursiva
    y n^k es la potencia que acumulamos en cada llamada recursiva.
 }
 *
*/
// función que resuelve el problema
void resolver(int n, int unidad_anterior, int pot, int& sol) {
    int unidad = n % 10;
    if (n > 0) {
        if (unidad_anterior == INT_MIN || unidad_anterior <= unidad) {
            sol += unidad * pot;
            resolver(n / 10, unidad, pot * 10, sol);
        }
        else {
            resolver(n / 10, unidad_anterior, pot, sol);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    //int pot = 1;
    int sol = 0;
    resolver(n, INT_MIN, 1, sol);
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