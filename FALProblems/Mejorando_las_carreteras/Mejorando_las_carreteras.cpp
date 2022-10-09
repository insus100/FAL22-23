// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int lli;
typedef long long unsigned int llui;

struct sol {
    lli ini;
    lli fin;
};

// función que resuelve el problema
int resolver(vector<int> &kms, llui const &n) {
    if (n < 3)
        return kms[0];
    /*else if (n == 2) {
        if (kms[0] >= kms[1])
            return kms[0];
        else
            return kms[1];
    }*/
    sort(kms.begin(), kms.end());
    sol Sol = { 0, -1 };
    int moda = -1;
    lli ini = -1, fin = -1;
    
    for (llui i = 0; i < n - 1; i++) {
        if (kms[i] == kms[i + 1]) {
            if (ini == -1) {
                ini = i;
                fin = i + 1;
            }
            else fin = i + 1;
            
            if (fin - ini > Sol.fin - Sol.ini) {
                Sol.ini = ini;
                Sol.fin = fin;
                moda = kms[i];
            }
        }
        else {
            ini = -1;
        }
    }

    return moda;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    llui num_accidentes;
    cin >> num_accidentes;
    if (num_accidentes == -1)
        return false;

    vector<int> kilometros(num_accidentes);

    for (llui i = 0; i < num_accidentes; i++) {
        cin >> kilometros[i];
    }
    cout << resolver(kilometros, num_accidentes) << "\n";

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
