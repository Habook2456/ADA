#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

const double INF = std::numeric_limits<double>::infinity();

double calculateDistance(std::pair<int, int> p1, std::pair<int, int> p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return std::sqrt(dx*dx + dy*dy);
}

double tsp(std::vector<std::pair<int, int>>& points) {
    int n = points.size();
    int numSubsets = 1 << n; // 2^n
    std::vector<std::vector<double>> dp(n, std::vector<double>(numSubsets, INF));
    
    dp[0][1] = 0;
    
    for (int subset = 1; subset < numSubsets; ++subset) {
        for (int last = 0; last < n; ++last) {
            if ((subset & (1 << last)) != 0) {
                if (subset == (1 << last)) {
                    continue;
                }
                for (int curr = 0; curr < n; ++curr) {
                    if ((subset & (1 << curr)) != 0 && curr != last) {
                        int prevSubset = subset ^ (1 << last);
                        dp[last][subset] = std::min(dp[last][subset], dp[curr][prevSubset] + calculateDistance(points[curr], points[last]));
                    }
                }
            }
        }
    }
    
    double minDist = INF;
    int finalSubset = (1 << n) - 1;
    for (int last = 1; last < n; ++last) {
        minDist = std::min(minDist, dp[last][finalSubset] + calculateDistance(points[last], points[0]));
    }
    
    return minDist;
}

int main() {
    std::vector<std::pair<int, int>> points = {{0, 0}, {1, 1}, {3, 3}, {2, 2}};
    double minDistance = tsp(points);
    
    if (minDistance == INF) {
        std::cout << "No se encontró una solución válida." << std::endl;
    } else {
        std::cout << "La distancia mínima del TSP es: " << minDistance << std::endl;
    }
    
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