#include <iostream>
#include <vector>

// Función auxiliar para combinar dos arrays ordenados
std::vector<int> mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    std::vector<int> merged;
    int i = 0, j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();

    // Combinar los elementos de los dos arrays en orden ascendente
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Agregar los elementos restantes del primer array, si hay alguno
    while (i < n1) {
        merged.push_back(arr1[i]);
        i++;
    }

    // Agregar los elementos restantes del segundo array, si hay alguno
    while (j < n2) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

// Función principal para combinar k arrays ordenados en uno solo
std::vector<int> mergeKArrays(std::vector<std::vector<int>>& arrays) {
    int k = arrays.size();

    // Caso base: si solo hay un array, devolverlo como resultado
    if (k == 1) {
        return arrays[0];
    }

    // Divide y combina recursivamente los arrays hasta llegar a un único array
    while (arrays.size() > 1) {
        std::vector<std::vector<int>> mergedArrays;
        int i = 0;

        // Combinar los arrays de dos en dos
        while (i < arrays.size() - 1) {
            std::vector<int> merged = mergeArrays(arrays[i], arrays[i + 1]);
            mergedArrays.push_back(merged);
            i += 2;
        }

        // Si hay un array sobrante, agregarlo al final sin combinar
        if (i == arrays.size() - 1) {
            mergedArrays.push_back(arrays[i]);
        }

        arrays = mergedArrays;
    }

    // El resultado final será el único array restante
    return arrays[0];
}

// Ejemplo de uso
int main() {
    std::vector<std::vector<int>> arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    std::vector<int> mergedArray = mergeKArrays(arrays);

    // Imprimir el array resultante
    for (int num : mergedArray) {
        std::cout << num << " ";
    }

    return 0;
}


/*
11. Supongamos que tenemos k arrays ordenados, cada uno con n elementos, y
queremos combinarlos en un único array ordenado con kn elementos. Una
posible alternativa consiste en, utilizando un algoritmo clásico, mezclar los dos
primeros arrays, posteriormente mezclar el resultado con el tercero, y así
sucesivamente.
a. ¿Cuál sería el tiempo de ejecución de este algoritmo?
El tiempo de ejecución del algoritmo clásico que mezcla los k arrays ordenados uno a uno sería O(nk^2), 
donde n es el número de elementos en cada array. Esto se debe a que se realizarían k-1 mezclas, cada una 
con una complejidad de O(nk), ya que se deben comparar y mezclar los elementos de los dos arrays en cada paso.
a. El tiempo de ejecución del algoritmo descrito, que mezcla los k arrays de manera secuencial, sería O(kn^2). 
Esto se debe a que en cada paso de mezcla, se deben recorrer todos los elementos de los dos arrays para encontrar el 
menor elemento y colocarlo en el array resultante. Dado que hay kn elementos en total y se deben realizar k-1 pasos 
de mezcla, el tiempo total será proporcional a k * (n + 2n + 3n + ... + kn) = kn(k+1)/2 = O(kn^2).
b. Diseñe un algoritmo de mezcla más eficiente.
Una alternativa más eficiente para combinar los k arrays en un único array ordenado es utilizando la técnica de "Merge Sort" (ordenamiento por mezcla). 
Este algoritmo tiene un tiempo de ejecución de O(kn log kn), lo cual es mucho más eficiente que el enfoque secuencial anterior.
*/