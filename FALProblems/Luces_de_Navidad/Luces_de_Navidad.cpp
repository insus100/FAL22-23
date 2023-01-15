/*
 * Nombre y usuarios de la pareja:
 * Javier Gil Caballero F32
 * Íñigo Velasco Sánchez F70
 * Puesto 0918
 *
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



/*
 * Usa las funciones auxiliares que necesites
 * Explica el espacio de búsqueda, la solución y los marcadores
 *
 */

bool valida(const int& k, int& consumoTotal, int& soluciones, vector<int>& usos, vector<int>& tira, int& maxcomsumo) {
    if (k > 1 && tira[k - 1] == tira[k] && tira[k - 2] == tira[k])
        return false;

    bool ok = true;
    for (int i = 0; i < usos.size() && ok; ++i) {
        if (usos[i] - ((k + 1) - usos[i]) > 1)
            ok = false;
    }
    if (!ok)
        return false;
    if (consumoTotal > maxcomsumo)
        return false;

    return true;
}
void resolver(const int&k, int& consumoTotal, int& solTotal, vector<int>&usos, vector<int>& tira, int &maxcomsumo,int &longitud, int &ncolores, const vector<int>&luces) {
    for (int color = 0; color < ncolores; ++color) {

        tira[k] = color;

        ++usos[color];

        consumoTotal += luces[color];

        if (valida(k, consumoTotal, solTotal, usos, tira, maxcomsumo)) {

            if (longitud - 1 == k)
                solTotal++;
            else {
                resolver(k+1, consumoTotal, solTotal, usos, tira, maxcomsumo, longitud, ncolores, luces);
            }

        }
        usos[color]--;
        consumoTotal -= luces[color];
    }
}

bool resuelveCaso() {
    int longitud, ncolores, maxconsumo;
    //lectura
    cin >> longitud;
    if (longitud == 0)
        return false;
    cin >> ncolores >> maxconsumo;

    vector<int> luces(ncolores);
    for (int& l : luces) {
        cin >> l;
    }

    //Variables extra (solución, marcadores, etc), llamada a la función 
    // y escribe la solución
    int consumo = 0, soluciones = 0;
    vector<int> tira(longitud);
    vector<int> usos(ncolores);


    resolver(0, consumo, soluciones, usos, tira, maxconsumo, longitud, ncolores, luces);
    cout << soluciones << "\n";

    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
