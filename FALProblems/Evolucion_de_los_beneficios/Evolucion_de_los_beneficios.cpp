// Nombre del alumno Javier Gil Caballero F32, Íñigo Velasco Sánchez (F70)


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
/*
* pre: { 0 <= N < v.size() }
* fun resuelve(vector<int> v, int num_anios, int anio1) dev sol : vector<int>
* post: { sol = Exists(i, j), 0 <= i < j < v.size() - 1 /\ v[i] < v[j] && max:(v[j], max(v[i], v[j])) < v[j] }
* 
* El coste de la funcion resolver es O(n) siendo n el numero de datos de entrada.
*/
// función que resuelve el problema
vector<int> resolver(vector<int> const& v, int const &num_anios, int const& anio1) {
    vector<int> sol;
    int cont_anio = anio1;
    int max = v[0];
    for (int i = 0; i < num_anios - 1; i++) {
        if (v[i] < v[i + 1] && v[i + 1] > max) {
            cont_anio += i;
            sol.push_back(cont_anio);
            cont_anio = anio1;
            max = v[i + 1];
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int anio1, anio2;
    cin >> anio1 >> anio2;
    int num_anios = anio2 - anio1 + 1;
    vector<int> anios(num_anios);
    for (int i = 0; i < num_anios; i++) {
        cin >> anios[i];
    }
    // escribir sol
    vector<int> sol = resolver(anios, num_anios, anio1 + 1);
    for (int v : sol)
        cout << v << " ";

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