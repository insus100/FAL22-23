

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tMarcas {
    int no_mejora_ini = 0;
    int no_mejora_fin = 0;
    int periodo = 0;
};
// función que resuelve el problema
tMarcas resolver(vector<int> marcas) {
    int ini_act = 0, fin_act = 0, periodo_act = 0, max_actual = 0;
    tMarcas sol;
    for (int i = 0; i < marcas.size(); i++) {
        if (marcas[i] > max_actual) {//si el elemento que está en i es mayor al maximo se resetea todo
            max_actual = marcas[i];
            ini_act = 0;
            fin_act = 0;
            periodo_act = 0;
        }
        else {//el elemento en i es menor al maximo
            fin_act = i;
            ini_act = fin_act - periodo_act;
            periodo_act++;
            if (periodo_act >= sol.periodo) {//cogemos el ultimo periodo que lo cumpla
                sol.no_mejora_ini = ini_act;
                sol.no_mejora_fin = fin_act;
                sol.periodo = periodo_act;
            }
        }
    }
    if (ini_act == 00 && sol.no_mejora_ini == 0) {//si siempre bate la marca se devuelve marcas.size() porque es el ultimo periodo que no bate la marca
        sol.no_mejora_ini = marcas.size();
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int marca, num;
    cin >> marca;
    if (marca == 0)
        return false;
    vector<int> marcas;
    for (int i = 0; i < marca; i++) {
        cin >> num;
        marcas.push_back(num);
    }
    tMarcas sol = resolver(marcas);

    // escribir sol
    cout << sol.periodo << " " << sol.no_mejora_ini << "\n";
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