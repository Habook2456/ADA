#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Algoritmo greedy para maximizar el número de programas almacenados en el disco
int maximizarNumProgramas(vector<int>& programas, int capacidadDisco) {
    sort(programas.begin(), programas.end()); // Ordenar los programas en orden no decreciente

    int numProgramas = 0;
    int espacioDisponible = capacidadDisco;

    for (int i = 0; i < programas.size(); i++) {
        if (programas[i] <= espacioDisponible) {
            numProgramas++;
            espacioDisponible -= programas[i];
        }
    }

    return numProgramas;
}

// Algoritmo greedy para aprovechar al máximo la capacidad del disco
int aprovecharCapacidadDisco(vector<int>& programas, int capacidadDisco) {
    sort(programas.rbegin(), programas.rend()); // Ordenar los programas en orden no creciente

    int espacioUtilizado = 0;

    for (int i = 0; i < programas.size(); i++) {
        if (programas[i] + espacioUtilizado <= capacidadDisco) {
            espacioUtilizado += programas[i];
        }
    }

    return espacioUtilizado;
}

int main() {
    int capacidadDisco;
    cout << "Ingrese la capacidad del disco en megabytes: ";
    cin >> capacidadDisco;

    int n;
    cout << "Ingrese la cantidad de programas: ";
    cin >> n;

    vector<int> programas(n);
    cout << "Ingrese los requerimientos de espacio de los programas en megabytes: ";
    for (int i = 0; i < n; i++) {
        cin >> programas[i];
    }

    int numProgramasAlmacenados = maximizarNumProgramas(programas, capacidadDisco);
    cout << "El número máximo de programas almacenados en el disco es: " << numProgramasAlmacenados << endl;

    int espacioUtilizado = aprovecharCapacidadDisco(programas, capacidadDisco);
    cout << "El espacio máximo utilizado en el disco es: " << espacioUtilizado << " megabytes" << endl;

    return 0;
}
/*2. Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si
 megabytes de espacio y la capacidad del disco es D megabytes,
siendo D < ΣSi
. Resuelva las siguientes cuestiones:
a. Diseñe un algoritmo greedy que maximice el número de programas
almacenados en el disco (existe un algoritmo que proporciona una
solución óptima).
b. Diseñe un algoritmo greedy que intente aprovechar al máximo la
capacidad del disco (demuestre que podemos utilizar un algoritmo
greedy que seleccione los programas por orden no creciente para obtener
la solución exacta o encuentre un contraejemplo de lo contrario). */