// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
typedef long long int llint;

// función que resuelve el problema
llint resolver(vector<llint> const & nacimientos, int const &index1, int const &index2) {
    if (index1 == 0) {
        return nacimientos[index2];
    }
    return nacimientos[index2] - nacimientos[index1 - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int anio_ini, anio_fin;
    cin >> anio_ini >> anio_fin;

    if (anio_ini == 0)
        return false;
    int n = anio_fin - anio_ini + 1;
    llint acumulado = 0, nacimiento;
    vector<llint> nacimientos(n);
    for (int i = 0; i < n; i++) {
        cin >> nacimiento;
        acumulado += nacimiento;
        nacimientos[i] = acumulado;//se va guardando los nacimientos totales hasta ese año
    }

    int num_preguntas;
    cin >> num_preguntas;
    for (int i = 0; i < num_preguntas; i++) {
        int anio1, anio2;
        cin >> anio1 >> anio2;
        anio1 = anio1 - anio_ini;//obtenemos los indices para mirar en el vector
        anio2 = anio2 - anio_ini;
        cout << resolver(nacimientos, anio1, anio2) << "\n";
    }
    cout << "---\n";

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
