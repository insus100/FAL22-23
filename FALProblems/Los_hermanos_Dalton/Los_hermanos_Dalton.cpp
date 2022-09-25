// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& datos, const int &N) {
    bool dalton = true;
    int i = 0;
    while(dalton && i < N - 1) {//creciente de izquierda a derecha
        if (datos[i] >= datos[i + 1])
            dalton = false;
        i++;
    }

    if (!dalton) {
        dalton = true;
        i = N - 1;
        while (dalton && i > 0) {
            if (datos[i - 1] <= datos[i])
                dalton = false;
            i--;
        }
    }

    return dalton;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N == 0)
        return false;

    vector<int> alturas(N);
    for (int i = 0; i < N; ++i) {
        cin >> alturas[i];
    }
    bool sol = resolver(alturas, N);
    // escribir sol
    sol ? cout << "DALTON" : cout << "DESCONOCIDOS";
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
