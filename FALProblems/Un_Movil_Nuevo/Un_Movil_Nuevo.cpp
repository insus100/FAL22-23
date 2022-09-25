// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
// función que resuelve el problema
vector<int> resolver(const vector<int> &precios1, const vector<int>& precios2, const int &n1, const int &n2) {

    if (n1 == 0)//si el primer vector esta vacio devuelvo el segundo y viceversa
        return precios2;
    else if (n2 == 0)
        return precios1;

    vector<int> sol;
    int i = 0, j = 0;
    while (i < n1 || j < n2) {

        if (n1 == i) {
            sol.push_back(precios2[j]);
            j++;
        }
        else if (n2 == j) {
            sol.push_back(precios1[i]);
            i++;
        }
        else if (precios1[i] < precios2[j]) {
            sol.push_back(precios1[i]);
            i++;
        }
        else if(precios1[i] > precios2[j]) {
            sol.push_back(precios2[j]);
            j++;
        }
        else {//valores iguales
            sol.push_back(precios1[i]);
            j++;
            i++;
        }
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N1, N2;
    cin >> N1 >> N2;
    vector<int> precios1(N1), precios2(N2);
    if (N1 != 0) {
        for (int i = 0; i < N1; ++i)
            cin >> precios1[i];
    }
    if (N2 != 0) {
        for (int i = 0; i < N2; ++i)
            cin >> precios2[i];
    }
    vector<int> sol = resolver(precios1, precios2, N1, N2);
    // escribir sol
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