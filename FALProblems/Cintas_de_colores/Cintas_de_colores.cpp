// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Cinta {
    char color;
    int longitud;
    bool operator<(Cinta const& b) const {//comparador de cintas: azul < verde < rojo
        if (color == 'a' && b.color == 'v' || color == 'a' && b.color == 'r' || color == 'v' && b.color == 'r') {
            return true;
        }
        return false;
    }
};

struct Sol {//dónde empiezan y terminan las cintas verdes
    int ini;
    int fin;
};
void increment(int& index, int const& max) {
    if (index + 1 < max) index++;
}
// función que resuelve el problema
Sol resolver(vector<Cinta> &v, int const &n) {
    int i = 0, j = 1;
    Sol sol{ -1, -1 };
    while (i < n && j < n) {
        if (v[i] < v[j]) increment(j, n);
        else if(v[j] < v[i]) {//cambiamos v[i] por v[j]
            Cinta aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            increment(i, n);
        } else increment(j, n);
    }
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
    for (int i = 0; i < n; i++) {
        cin >> v[i].color >> v[i].longitud;
    }
    Sol sol = resolver(v, n);
    // escribir sol
    cout << "Azules: ";
    for (int i = 0; i < sol.ini; i++)
        cout << v[i].longitud << " ";
    cout << "\nVerdes: ";
    for (int i = sol.ini; i < sol.fin; i++)
        cout << v[i].longitud << " ";
    cout << "\nRojas: ";
    for (int i = sol.fin; i < v.size(); i++)
        cout << v[i].longitud << " ";
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