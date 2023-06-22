#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> encontrarSecuenciaCreciente(vector<int>& V) {
    int n = V.size();
    vector<int> dp(n, 1);  // dp[i] representa la longitud de la secuencia creciente hasta el índice i
    vector<int> prev(n, -1);  // prev[i] guarda el índice anterior en la secuencia creciente que termina en i

    // Calcular las longitudes de las secuencias crecientes para cada elemento
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[i] > V[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Encontrar la longitud máxima y el índice correspondiente
    int maxLen = *max_element(dp.begin(), dp.end());
    int maxIdx = max_element(dp.begin(), dp.end()) - dp.begin();

    // Construir la secuencia creciente de máxima longitud
    vector<int> secuencia;
    while (maxIdx != -1) {
        secuencia.push_back(V[maxIdx]);
        maxIdx = prev[maxIdx];
    }
    reverse(secuencia.begin(), secuencia.end());

    return secuencia;
}

int main() {
    vector<int> V = {11, 17, 5, 8, 6, 4, 7, 12, 3};

    vector<int> secuencia = encontrarSecuenciaCreciente(V);

    cout << "Secuencia creciente de máxima longitud: ";
    for (int num : secuencia) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
/*4. Secuencia creciente de máxima longitud:
Sea V un vector con n valores enteros distintos. Diseñe un algoritmo eficiente
basado en programación dinámica para encontrar la secuencia creciente de
máxima longitud en V. Por ejemplo si el vector de entrada es (11, 17, 5, 8, 6, 4,
7, 12, 3), la secuencia creciente de máxima longitud es (5, 6, 7, 12). 
*/