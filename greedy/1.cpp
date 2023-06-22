#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizarNumContenedores(vector<int>& contenedores, int capacidadBuque) {
    sort(contenedores.begin(), contenedores.end()); // Ordenar los contenedores en orden ascendente

    int numContenedores = 0;
    int capacidadRestante = capacidadBuque;

    for (int i = 0; i < contenedores.size(); i++) {
        if (contenedores[i] <= capacidadRestante) {
            numContenedores++;
            capacidadRestante -= contenedores[i];
        }
    }

    return numContenedores;
}

int main() {
    int capacidadBuque;
    cout << "Ingrese la capacidad del buque en toneladas: ";
    cin >> capacidadBuque;

    int n;
    cout << "Ingrese la cantidad de contenedores: ";
    cin >> n;

    vector<int> contenedores(n);
    cout << "Ingrese los pesos de los contenedores en toneladas: ";
    for (int i = 0; i < n; i++) {
        cin >> contenedores[i];
    }

    int numContenedoresCargados = maximizarNumContenedores(contenedores, capacidadBuque);
    cout << "El número máximo de contenedores cargados es: " << numContenedoresCargados << endl;

    return 0;
}
/*1. Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un
conjunto de contenedores c1, …, cn cuyos pesos respectivos son p1, …, pn
(expresados también en toneladas). Teniendo en cuenta que la capacidad del
buque es menor que la suma total de los pesos de los contenedores:
a. Diseñe un algoritmo que maximice el número de contenedores cargados.
b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas. */