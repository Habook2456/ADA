#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

class graph
{
public:
    vector<vector<pair<int, int>>> adjList;
    int numVertices;
    graph(int V)
    {
        numVertices = V;
        adjList.resize(numVertices);
    }
    void add(int v1, int v2, int weight)
    {
        adjList[v1].push_back(make_pair(v2, weight));
        adjList[v2].push_back(make_pair(v1, weight));
    }
    void printGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            std::cout << "Vertice " << i << ": ";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                std::cout << "(" << adjList[i][j].first << ", " << adjList[i][j].second << ") ";
            }
            std::cout << endl;
        }
    }

    void dijkstra(int start)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<bool> visited(numVertices, false);
        vector<int> distances(numVertices, INT_MAX);
        deque<deque<int>> padre(numVertices, deque<int>(1, start));
        pq.push(make_pair(0, start));
        distances[start] = 0;

        while (!pq.empty())
        {
            int currentVertex = pq.top().second;
            pq.pop();
            if (visited[currentVertex])
            {
                continue;
            }

            visited[currentVertex] = true;

            for (auto it = adjList[currentVertex].begin(); it != adjList[currentVertex].end(); it++)
            {
                int destVertex = (*it).first;
                int weight = (*it).second;

                if (visited[destVertex] == false && distances[currentVertex] + weight < distances[destVertex])
                {
                    distances[destVertex] = distances[currentVertex] + weight;
                    pq.push(make_pair(distances[destVertex], destVertex));
                    if (!(find(padre[destVertex].begin(), padre[destVertex].end(), currentVertex) != padre[destVertex].end()) && distances[currentVertex] + weight == distances[destVertex])
                    {
                        padre[destVertex].push_back(currentVertex);
                    }
                }
            }
        }

        for (int i = 0; i < distances.size(); i++)
        {
            std::cout << "distancia " << start << " hacia " << i << ": " << distances[i] << std::endl;
        }

        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " -> ";
            if (!padre[i].empty())
            {
                for (int j = padre[i].size() - 1; j >= 0; j--)
                {
                    cout << padre[i][j];
                    if (j > 0)
                    {
                        cout << " -> ";
                    }
                }
            }
            else
            {
                cout << "No hay camino";
            }
            cout << endl;
        }
    }

    void dijkstraPath()
    {
    }
};

void initGraph(graph &g)
{
    g.add(0, 1, 2);
    g.add(0, 2, 3);
    g.add(0, 3, 1);
    g.add(1, 2, 3);
    g.add(1, 4, 6);
    g.add(2, 4, 7);
    g.add(2, 5, 6);
    g.add(3, 5, 2);
    g.add(3, 6, 4);
    g.add(4, 5, 9);
    g.add(5, 6, 7);
}
int main()
{
    graph g(7);
    initGraph(g);
    g.printGraph();
    std::cout << "\nDijkstra Algorithm\n";
    g.dijkstra(0);
    return 0;
}