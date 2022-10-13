// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
using llui = long long unsigned int;
struct max_punt {
    llui pagina;
    llui puntuacion;
};
// función que resuelve el problema
llui suma_segmento(const std::vector<llui>& datos, llui ini, llui fin, const llui& maximo, unsigned int& esta_el_max) {
    llui ret = 0;
    while (ini < fin) {
        ret += datos[ini];
        ini++;
        if (datos[ini] == maximo)
            esta_el_max++;
    }
    return ret;
}

// función que resuelve el problema
llui resolver(const std::vector<llui>& datos, const llui& paginas_leer, const llui& maximo) {
    llui suma_mayor = 0, suma_puntuaciones = 0, ini = 0, fin = paginas_leer, ret = 0;
    unsigned int esta_el_max_en_el_segmento = 0;//cuenta cuantas veces aparece el maximo en el segmento, si es 0 significa que el maximo no esta en el segmento
    suma_puntuaciones = suma_segmento(datos, ini, fin, maximo, esta_el_max_en_el_segmento);//suma del primer segmento;
    if (esta_el_max_en_el_segmento > 0)
        suma_mayor = suma_puntuaciones;//la suma mayor solo me sirve si la pagina con puntuacion maxima está en el segmento

    ini++;
    fin++;
    while (fin <= datos.size()) {//va modificando la suma de acuerdo al primer y al ultimo valor
        suma_puntuaciones -= datos[ini - 1];
        if (datos[ini - 1] == maximo) {
            if (esta_el_max_en_el_segmento > 0)
                esta_el_max_en_el_segmento--;//si he sacado el maximo del segmento
        }


        suma_puntuaciones += datos[fin - 1];
        if (datos[fin - 1] == maximo)
            esta_el_max_en_el_segmento++;

        if (suma_puntuaciones >= suma_mayor && esta_el_max_en_el_segmento > 0) {
            suma_mayor = suma_puntuaciones;
            ret = ini;
        }
        ini++;
        fin++;
    }
    return ret;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int total_paginas, max_paginas;
    cin >> total_paginas >> max_paginas;
    if (total_paginas == 0)
        return false;
    vector<llui> puntuaciones(total_paginas);
    max_punt mp = { -1, 0 };
    for (int i = 0; i < total_paginas; i++) {
        cin >> puntuaciones[i];
        if (puntuaciones[i] >= mp.puntuacion) {
            mp.puntuacion = puntuaciones[i];
            mp.pagina = i;
        }
    }

    cout << resolver(puntuaciones, max_paginas, mp.puntuacion) << "\n";

    // escribir sol

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
