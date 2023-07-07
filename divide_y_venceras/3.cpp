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

// Función auxiliar para encontrar la mediana de un subconjunto del vector
int findMedian(vector<int>& vec, int start, int end) {
    int n = end - start + 1;
    int medianIdx = start + n / 2;

    // Algoritmo de selección rápida (Quickselect)
    while (start < end) {
        int pivotIdx = start;
        int left = start + 1;
        int right = end;

        while (left <= right) {
            if (vec[left] > vec[pivotIdx] && vec[right] < vec[pivotIdx]) {
                swap(vec, left, right);
            }
            if (vec[left] <= vec[pivotIdx]) {
                left++;
            }
            if (vec[right] >= vec[pivotIdx]) {
                right--;
            }
        }

        swap(vec, pivotIdx, right);

        if (right == medianIdx) {
            break;
        } else if (right < medianIdx) {
            start = right + 1;
        } else {
            end = right - 1;
        }
    }

    return vec[medianIdx];
}

// Función principal para encontrar la mediana del vector
int findMedian(vector<int>& vec) {
    int n = vec.size();
    return findMedian(vec, 0, n - 1);
}

int main() {
    // Ejemplo de uso
    vector<int> vec = {9, 2, 7, 4, 5, 3, 8, 1, 6};
    int median = findMedian(vec);
    cout << "La mediana del vector es: " << median << endl;

    return 0;
}

/*

7. Diseñe un algoritmo "divide y vencerás" que permita encontrar la mediana de un
vector sin tener que ordenar el vector previamente.


*/