// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Sol {
    int sumaParesMasProdImparesIzq;
    int prodParesMasSumaImparesDer;
    bool esExtrano;
};

// función que resuelve el problema
Sol resolver(vector<int> const&v, int ini, int fin) {
    if (ini == fin) {
        return { 0, 0, true };
    }
    else if (ini + 1 == fin) {
        if (v[ini] <= v[fin]) return { v[ini], v[fin], true };
        else return { v[ini], v[fin], false };
    }
    else {
        int mitad = (ini + fin) / 2;
        Sol izq = resolver(v, ini, mitad);
        Sol der = resolver(v, mitad + 1, fin);
        return { 0,0, izq.sumaParesMasProdImparesIzq <= der.prodParesMasSumaImparesDer && izq.esExtrano && der.esExtrano };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;
    vector<int> v(tam);
    for(int i = 0; i < tam; i++){
        cin >> v[i];
    } 

    Sol sol = resolver(v, 0, tam - 1);
    // escribir sol
    sol.esExtrano ? cout << "SI" : cout << "NO";
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