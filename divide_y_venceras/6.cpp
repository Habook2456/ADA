
#include <iostream>
#include <vector>

using namespace std;

// Función auxiliar para realizar la búsqueda "divide y vencerás"
bool searchIndexEqualsValue(const vector<int>& X, int start, int end) {
    if (start > end) {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (X[mid] == mid) {
        cout << "indice " << mid << ": " << X[mid] << endl;
        return true;
    } else if (X[mid] > mid) {
        return searchIndexEqualsValue(X, start, mid - 1);
    } else {
        return searchIndexEqualsValue(X, mid + 1, end);
    }
}

// Función principal para determinar si existe un índice i tal que X[i] = i
bool existsIndexEqualsValue(const vector<int>& X) {
    int n = X.size();
    return searchIndexEqualsValue(X, 0, n - 1);
}

int main() {
    // Ejemplo de uso
    vector<int> X = {-3, -1, 0, 1, 3, 5, 8};
    bool exists = existsIndexEqualsValue(X);

    if (exists) {
        cout << "Existe un indice i tal que X[i] = i" << endl;
    } else {
        cout << "No existe un indice i tal que X[i] = i" << endl;
    }

    return 0;
}



/*

10. Dado un vector ordenado de números enteros X, diseñe un algoritmo "divide y
vencerás" que permita determinar si existe un índice i tal que X[i] = i. 

*/