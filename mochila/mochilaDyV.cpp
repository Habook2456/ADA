#include <iostream>
#include <vector>
using namespace std;

// Función auxiliar para calcular el máximo de dos números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función recursiva que resuelve el problema de la mochila
int mochilaDV(vector<int>& peso, vector<int>& beneficio, int capacidad, int n) {
    // Caso base: si no hay elementos o no hay capacidad, el beneficio es 0
    if (n == 0 || capacidad == 0)
        return 0;

    // Si el peso del último elemento es mayor que la capacidad, no se puede incluir
    if (peso[n - 1] > capacidad)
        return mochilaDV(peso, beneficio, capacidad, n - 1);

    // Caso general:
    // Se divide el problema en dos subproblemas:
    // 1. Incluir el último elemento y buscar el máximo beneficio con la capacidad restante
    // 2. Excluir el último elemento y buscar el máximo beneficio con la misma capacidad
    else
        return max(beneficio[n - 1] + mochilaDV(peso, beneficio, capacidad - peso[n - 1], n - 1),
                   mochilaDV(peso, beneficio, capacidad, n - 1));
}

int main() {
    vector<int> peso = {1, 2, 5, 6, 7};
    vector<int> beneficio = {1, 6, 18, 22, 28};
    int capacidad = 11;
    int n = peso.size();

    int maxBeneficio = mochilaDV(peso, beneficio, capacidad, n);
    cout << "El beneficio máximo obtenido es: " << maxBeneficio << endl;

    return 0;
}
