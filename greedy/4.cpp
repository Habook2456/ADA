#include <iostream>
#include <vector>
#include <unordered_set>

struct Edge {
    int u;
    int v;

    Edge(int vertexU, int vertexV) : u(vertexU), v(vertexV) {}
};

std::unordered_set<int> findMinimalCover(const std::vector<Edge>& edges) {
    std::unordered_set<int> cover;
    std::unordered_set<int> coveredVertices;

    for (const Edge& edge : edges) {
        if (coveredVertices.find(edge.u) == coveredVertices.end() &&
            coveredVertices.find(edge.v) == coveredVertices.end()) {
            cover.insert(edge.u);
            cover.insert(edge.v);
            coveredVertices.insert(edge.u);
            coveredVertices.insert(edge.v);
        }
    }

    return cover;
}

int main() {
    std::vector<Edge> edges;
    edges.emplace_back(1, 2);
    edges.emplace_back(1, 3);
    edges.emplace_back(2, 3);
    edges.emplace_back(2, 4);
    edges.emplace_back(2, 5);
    edges.emplace_back(3, 4);
    edges.emplace_back(4, 5);
    edges.emplace_back(4, 6);
    edges.emplace_back(5, 6);
    edges.emplace_back(5, 7);
    edges.emplace_back(6, 7);
    edges.emplace_back(6, 8);
    edges.emplace_back(6, 9);
    edges.emplace_back(7, 8);
    edges.emplace_back(8, 9);
    edges.emplace_back(8, 10);
    edges.emplace_back(9, 10);

    std::unordered_set<int> minimalCover = findMinimalCover(edges);

    std::cout << "Recubrimiento minimal: ";
    for (int vertex : minimalCover) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*

4. Consideremos un grafo no dirigido G = (V, E). Un conjunto de nodos U se dice
que es un recubrimiento de G si U es un subconjunto de V tal que cada arista en
E incide en, al menos, un vértice de U. Un conjunto de nodos es un
recubrimiento minimal de G si es un recubrimiento con el número mínimo
posible de nodos.
a. Diseñe un algoritmo greedy para obtener un recubrimiento de G.
b. Indique si el algoritmo greedy devuelve un recubrimiento minimal para
cualquier grafo si, como función de selección, se escoge el nodo con
mayor grado de incidencia de entre los nodos aún no seleccionados.
NOTA:
El grado de incidencia de un vértice es el número de aristas que inciden en él*/