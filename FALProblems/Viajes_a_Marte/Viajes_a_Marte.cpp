// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Viajero {
    string nombre;
    int altura;
};
// función que resuelve el problema
bool comparaNombre(const Viajero& a, const Viajero& b)
{
    return a.nombre < b.nombre;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    int umbral;
    cin >> umbral;
    Viajero v;
    vector<Viajero> altos, bajos;
    for (int i = 0; i < n; i++) {
        cin >> v.nombre >> v.altura;
        v.altura > umbral ? altos.push_back(v) : bajos.push_back(v);
    }
    // escribir sol
    sort(altos.begin(), altos.end(), comparaNombre);
    sort(bajos.begin(), bajos.end(), comparaNombre);
    cout << "Bajos: ";
    for (Viajero v : bajos) {
        cout << v.nombre << " ";
    }
    cout << "\n";
    cout << "Altos: ";
    for (Viajero v : altos) {
        cout << v.nombre << " ";
    }
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