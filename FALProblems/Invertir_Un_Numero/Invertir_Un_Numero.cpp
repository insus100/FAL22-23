

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
void solucion(int n, int a1, int& a2) {

    if (n > 0) {
        a1 = n % 10;
        n = n / 10;
        a2 = a2 * 10 + a1;
        solucion(n, a1, a2);
    }
}
bool resuelveCaso() {

    //Leer caso de prueba: cin>>...
    int num, a1 = 0, a2 = 0;
    cin >> num;
    if (num == 0)
        return false;
    //Resolver problema
    solucion(num, a1, a2);
    cout << a2 << endl;
    //Escribir resultado
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