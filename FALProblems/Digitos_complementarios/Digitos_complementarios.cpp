// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

using par = pair<int, int>;

// función que resuelve el problema
par resolverComplementario(int numero, int pot, int total) {
    if (numero < 10) {//caso base
        if (total == 0)
            return { pot, 9 - numero };
        else
            return { pot, (9 - (numero % 10)) * pot + total };
    }
    else {
        return resolverComplementario(numero / 10, pot * 10, (9 - (numero % 10)) * pot + total);
    }
}

int resolverInverso(int numero, int pot, int total) {
    if (numero < 10) {
        if (total == 0)
            return numero;
        else
            return pot * (numero % 10) + total;
    }
    else {
        return resolverInverso(numero / 10, pot / 10, pot * (numero % 10) + total);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    par complementario = resolverComplementario(n, 1, 0);//saca el complementario de n y la potencia maxima
    int inverso = resolverInverso(complementario.second, complementario.first, 0);//saca el inverso del complementario
    // escribir sol
    cout << complementario.second << " " << inverso << "\n";
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