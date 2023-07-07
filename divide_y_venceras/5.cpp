#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función auxiliar para fusionar dos vectores ordenados
vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> result;
    int i = 0, j = 0;
    int n1 = vec1.size();
    int n2 = vec2.size();

    while (i < n1 && j < n2) {
        if (vec1[i] < vec2[j]) {
            result.push_back(vec1[i]);
            i++;
        } else if (vec2[j] < vec1[i]) {
            result.push_back(vec2[j]);
            j++;
        } else {
            // Si los elementos son iguales, se omite uno de ellos para eliminar duplicados
            result.push_back(vec1[i]);
            i++;
            j++;
        }
    }

    // Agregar los elementos restantes de los vectores
    while (i < n1) {
        result.push_back(vec1[i]);
        i++;
    }
    while (j < n2) {
        result.push_back(vec2[j]);
        j++;
    }

    return result;
}

// Función principal para eliminar los elementos duplicados del vector utilizando "divide y vencerás"
vector<int> removeDuplicates(vector<int>& vec) {
    int n = vec.size();

    // Caso base: si el vector tiene un solo elemento, se devuelve tal cual
    if (n <= 1) {
        return vec;
    }

    // Dividir el vector en dos mitades
    int mid = n / 2;
    vector<int> left(vec.begin(), vec.begin() + mid);
    vector<int> right(vec.begin() + mid, vec.end());

    // Llamadas recursivas para eliminar duplicados en las dos mitades
    left = removeDuplicates(left);
    right = removeDuplicates(right);

    // Fusionar las dos mitades ordenadas sin duplicados
    return mergeSortedVectors(left, right);
}

int main() {
    // Ejemplo de uso
    vector<int> vec = {1,2,3,2,4,5,2,1,4,3,2,4,3,2,1,4};
    vector<int> result = removeDuplicates(vec);

    cout << "Vector original: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Vector sin duplicados: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
9. Dado un vector de n elementos, de los cuales algunos están duplicados, diseñe
un algoritmo O(n log n) que permita eliminar todos los elementos duplicados. 

*/