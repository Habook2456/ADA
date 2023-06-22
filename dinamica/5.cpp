#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dp(n, vector<int>(1 << n, INF));

    // Caso base: si S es vacío y estamos en el nodo 0, la distancia es 0
    dp[0][0] = 0;

    // Calcular las distancias mínimas utilizando programación dinámica con subconjuntos
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {  // Si el nodo i está en el subconjunto representado por el mask
                for (int j = 0; j < n; j++) {
                    if (i != j && (mask & (1 << j)) != 0) {  // Si el nodo j también está en el subconjunto
                        dp[i][mask] = min(dp[i][mask], graph[i][j] + dp[j][mask ^ (1 << i)]);
                    }
                }
            }
        }
    }

    // Encontrar la distancia mínima del camino hamiltoniano
    int minDist = INF;
    for (int i = 1; i < n; i++) {
        minDist = min(minDist, graph[i][0] + dp[i][(1 << n) - 1]);
    }

    return minDist;
}

int main() {
    int n;
    cout << "Ingrese el número de nodos: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Ingrese las distancias entre los nodos: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int minDist = tsp(graph, n);

    cout << "La longitud del camino más corto del problema del viajante de comercio es: " << minDist << endl;

    return 0;
}

/*5. Problema del viajante de comercio
Diseñe un algoritmo basado en programación dinámica para resolver el
problema del viajante de comercio en tiempo O(n2
2
n
). ¿Es este algoritmo mejor
que un algoritmo que explore todas las permutaciones posibles?
SUGERENCIA: Defina g(i,S) como la longitud del camino más corto que desde el
nodo i hasta el nodo 1 (donde comenzamos nuestro circuito) que pase
exactamente una vez por cada nodo del conjunto S. Con esta definición, dado un
grafo G(V,E), g(1,V-{1}) nos da la longitud del circuito hamiltoniano minimal. */