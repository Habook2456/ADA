#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función auxiliar para intercambiar elementos en el vector
void swap(vector<int>& vec, int i, int j) {
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

// Función auxiliar para encontrar la posición del pivote utilizando el algoritmo de partición
int partition(vector<int>& vec, int start, int end) {
    int pivot = vec[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec, i, j);
        }
    }

    swap(vec, i + 1, end);
    return i + 1;
}

// Función auxiliar para encontrar el k-ésimo menor elemento en el subconjunto del vector
int findKthSmallest(vector<int>& vec, int start, int end, int k) {
    if (k >= 1 && k <= end - start + 1) {
        int pivotIdx = partition(vec, start, end);

        if (pivotIdx - start == k - 1) {
            return vec[pivotIdx];
        } else if (pivotIdx - start > k - 1) {
            return findKthSmallest(vec, start, pivotIdx - 1, k);
        } else {
            return findKthSmallest(vec, pivotIdx + 1, end, k - pivotIdx + start - 1);
        }
    }

    return -1; // Valor inválido para indicar que no se encontró el k-ésimo menor elemento
}

// Función principal para calcular el k-ésimo menor elemento del vector
int findKthSmallest(vector<int>& vec, int k) {
    int n = vec.size();
    return findKthSmallest(vec, 0, n - 1, k);
}

int main() {
    // Ejemplo de uso
    vector<int> vec = {7,3,5,1,9};
    int k = 5; // Buscar el tercer elemento más pequeño
    int kthSmallest = findKthSmallest(vec, k);
    cout << "El " << k << "-esimo menor elemento del vector es: " << kthSmallest << endl;

    return 0;
}


/*

8. Diseñe un algoritmo "divide y vencerás" que permita calcular el k−ésimo menor
elemento de un vector. 

*/