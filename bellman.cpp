#include <iostream>
#include <vector>
#include <climits>
#include <stack>

struct Edge {
    int source, destination, weight;
};

void BellmanFord(const std::vector<Edge>& edges, int numVertices, int source) {
    std::vector<int> distances(numVertices, INT_MAX);
    std::vector<std::vector<int>> paths(numVertices);
    std::vector<int> predecessors(numVertices, -1);

    distances[source] = 0;
    paths[source].push_back(source);

    for (int i = 1; i < numVertices; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
                paths[v] = paths[u];
                paths[v].push_back(v);
            }
        }
    }

    // Verificar si hay ciclos de costo negativo
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            std::cout << "El grafo contiene un ciclo de costo negativo\n";
            return;
        }
    }

    // Imprimir los caminos mas cortos y los predecesores
    std::cout << "Distancias desde el vertice origen " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Hasta el vertice " << i << ": " << distances[i] << "\n";
    }

    std::cout << "Caminos mas cortos:\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertice " << i << ": ";
        for (int vertex : paths[i]) {
            std::cout << vertex << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int numVertices = 5;
    int source = 0;
    std::vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    BellmanFord(edges, numVertices, source);

    return 0;
}
