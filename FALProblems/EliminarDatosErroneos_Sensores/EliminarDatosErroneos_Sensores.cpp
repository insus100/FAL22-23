// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

// función que resuelve el problema
void resolver(vector<lli> &medidas, const lli &error) {
    int pos = 0;
    for (int i = 0; i < medidas.size(); i++) {
        if (medidas[i] != error) {
            medidas[pos] = medidas[i];
            pos++;
        }
    }
    medidas.resize(pos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    lli error;
    cin >> n >> error;
    vector<lli> medidas(n);
    for (lli& m : medidas)
        cin >> m;

    resolver(medidas, error);
    // escribir sol
    cout << medidas.size() << "\n";
    for (lli const& m : medidas)
        cout << m << " ";
    cout << "\n";
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