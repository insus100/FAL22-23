// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cinta {
    char color;
    int longitud;
    /*bool operator<(Cinta const& b) const {//comparador de cintas: azul < verde < rojo
        if (color == 'a' && b.color == 'v' || color == 'a' && b.color == 'r' || color == 'v' && b.color == 'r') {
            return true;
        }
        return false;
    }*/
    bool operator<=(Cinta const& b) const {
        return longitud <= b.longitud;
    }
};

bool ordenarPorLongitud(Cinta const& a, Cinta const& b) {
    return a.longitud <= b.longitud;
}

struct Sol {//dónde empiezan y terminan las cintas verdes
    int ini;
    int fin;
};
void intercambiar(vector<Cinta>& v, int const& a, int const& b) {//a y b son indices
    Cinta aux = v[b];
    v[b] = v[a];
    v[a] = aux;
}
// función que resuelve el problema
Sol resolver(vector<Cinta> &v, int n) {
    int i = 0, j = 0;
    Sol sol{ 0, 0 };
    while (j != n) {
        switch (v[j].color)
        {
        case 'a': {
            intercambiar(v, j, i);
            i++;
            j++;
            break;
        }
        case 'v': {
            j++;
            break;
        }
        case 'r': {
            intercambiar(v, j, n - 1);
            n--;
            break;
        }
        default:
            break;
        }
    }
    sol.ini = i;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!std::cin)
        return false;
    vector<Cinta> v(n);
    int verdes = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].color >> v[i].longitud;
        if (v[i].color == 'v')
            verdes++;
    }
    Sol sol = resolver(v, n);
    sol.fin = sol.ini + verdes;
    // escribir sol
    sort(v.begin(), v.begin() + sol.ini, ordenarPorLongitud);
    cout << "Azules: ";
    for (int i = 0; i < sol.ini; i++)
        cout << v[i].longitud << " ";

    sort(v.begin() + sol.ini, v.begin() + sol.fin, ordenarPorLongitud);
    cout << "\nVerdes: ";
    for (int i = sol.ini; i < sol.fin; i++)
        cout << v[i].longitud << " ";

    sort(v.begin() + sol.fin, v.begin() + n, ordenarPorLongitud);
    cout << "\nRojas: ";
    for (int i = sol.fin; i < v.size(); i++)
        cout << v[i].longitud << " ";
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