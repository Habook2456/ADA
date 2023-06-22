#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Edge {
    int u;
    int v;
};

vector<int> greedyCover(vector<Edge>& edges, int n) {
    vector<int> cover;
    vector<bool> selected(n, false);

    for (const Edge& edge : edges) {
        if (!selected[edge.u] && !selected[edge.v]) {
            selected[edge.u] = true;
            selected[edge.v] = true;
            cover.push_back(edge.u);
            cover.push_back(edge.v);
        }
    }

    return cover;
}

int main() {
    int n, m;
    cout << "Ingrese el número de nodos (V): ";
    cin >> n;
    cout << "Ingrese el número de aristas (E): ";
    cin >> m;

    vector<Edge> edges(m);
    cout << "Ingrese las aristas del grafo (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
    }

    vector<int> cover = greedyCover(edges, n);

    cout << "\nEl recubrimiento obtenido es: ";
    unordered_set<int> coverSet(cover.begin(), cover.end());
    for (int node : coverSet) {
        cout << node << " ";
    }
    cout << endl;

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