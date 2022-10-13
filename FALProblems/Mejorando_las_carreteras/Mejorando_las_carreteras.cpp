// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int lli;
//typedef long long unsigned int llui;
/*
No necesitas que Sean long long unsigned int. Aunque dice que “no está acotado” no hay ningún caso que tenga más de 2^32 -1 elementos.

Tú problema aparece cuando no hay valores repetidos (y tienes más de un único elemento). Prueba estos casos y verás que no haces lo que debes:
2
88 2
3
88 2 9

En ambos la respuesta debería ser 2

Un saludo,
   Ignacio

*/
struct sol {
    int ini;
    int fin;
};

// función que resuelve el problema
int resolver(vector<int> &kms, int const &n) {
    sort(kms.begin(), kms.end());
    if (n < 3)
        return kms[0];
    /*else if (n == 2) {
        if (kms[0] >= kms[1])
            return kms[0];
        else
            return kms[1];
    }*/
    
    sol Sol = { 0, 0 };
    int moda = -1;
    bool segmento = false;
    int ini = 0, fin = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (kms[i] == kms[i + 1]) {
            if (!segmento) {
                ini = i;
                fin = i + 1;
                segmento = true;
            }
            else fin = i + 1;
            
            if (fin - ini > Sol.fin - Sol.ini) {
                Sol.ini = ini;
                Sol.fin = fin;
                moda = kms[i];
            }
        }
        else {
            segmento = false;
        }
    }
    if (moda == -1)
        moda = kms[0];

    return moda;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num_accidentes;
    cin >> num_accidentes;
    if (num_accidentes == -1)
        return false;

    vector<int> kilometros(num_accidentes);

    for (int i = 0; i < num_accidentes; i++) {
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
