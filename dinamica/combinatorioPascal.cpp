#include <iostream>
#include <vector>

int calcular_combinatorio(int n, int k) {
    // Crear el triángulo de Pascal
    std::vector<std::vector<int>> triangulo(n + 1, std::vector<int>(n + 1, 0));
    triangulo[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        triangulo[i][0] = 1;
        triangulo[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangulo[i][j] = triangulo[i - 1][j - 1] + triangulo[i - 1][j];
        }
    }

    // Devolver el número combinatorio deseado
    return triangulo[n][k];
}

int main() {
    // Ejemplo de uso
    int n = 5;
    int k = 2;
    int resultado = calcular_combinatorio(n, k);
    std::cout << "El número combinatorio C(" << n << ", " << k << ") es: " << resultado << std::endl;

    return 0;
}
