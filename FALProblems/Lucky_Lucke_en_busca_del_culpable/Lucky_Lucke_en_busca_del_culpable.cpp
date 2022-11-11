// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int buscaIz(vector<int> const& v, int ini, int fin, int const &altura) {
    if (ini == fin) {
        if (v[ini] == altura) return ini;
        else return -1;
    }
    else if (ini + 1 == fin) {
        if (v[ini] == altura) return ini;
        else if (v[fin] == altura) return fin;
        else return -1;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] >= altura)
            return buscaIz(v, ini, mitad, altura);
        else
            return -1;
    }
}

int buscaDr(vector<int> const& v, int ini, int fin, int const& altura) {
    if (ini == fin) {
        if (v[ini] == altura) return ini;
        else return -1;
    }
    else if (ini + 1 == fin) {
        if (v[ini] == altura) return ini;
        else if (v[fin] == altura) return fin;
        else return -1;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] <= altura)
            return buscaDr(v, mitad + 1, fin, altura);
        else
            return -1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, a;
    cin >> n >> a;
    if (!std::cin)
        return false;
    vector<int> alturas(n);
    for (int i = 0; i < n; i++) {
        cin >> alturas[i];
    }
    int mitad = n / 2;
    int solIzq = -1, solDer = -1;
    if(alturas[mitad] >= a)
        solIzq = buscaIz(alturas, 0, mitad, a);
    if(alturas[mitad] <= a)
        solDer = buscaDr(alturas, mitad + 1, n - 1, a);
    // escribir sol
    if (solIzq == -1 && solDer == -1) {
        cout << "NO EXISTE\n";
    }
    else {
        if (solIzq == -1) cout << solDer << "\n";
        else if (solDer == -1) cout << solIzq << "\n";
        else cout << solIzq << " " << solDer << "\n";
    }
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