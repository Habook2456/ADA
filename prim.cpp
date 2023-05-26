#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
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

    void primAlgorithm()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int origen = 0;
        vector<bool> visitado(numVertices, false);
        vector<int> dist(numVertices, INT_MAX);
        vector<int> padre(numVertices, -1);
        pq.push(make_pair(0, origen));
        dist[origen] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            
            pq.pop();
            visitado[u] = true;
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++)
            {
                if (visitado[(*it).first] == false && (*it).second < dist[(*it).first])
                {
                    dist[(*it).first] = (*it).second;
                    padre[(*it).first] = u;
                    pq.push(make_pair(dist[(*it).first], (*it).first));
                }
            }
        }

        for (int i = 0; i < numVertices; i++)
        {
            if (padre[i] != -1)
            {
                std::cout << padre[i] << " -> " << i << endl;
            }
        }
    }
};

void initGraph(graph &g)
{
    g.add(0, 1, 2);
    g.add(0, 2, 3);
    g.add(0, 3, 1);
    g.add(1, 2, 3);
    g.add(1, 4, 8);
    g.add(2, 4, 7);
    g.add(2, 5, 6);
    g.add(3, 5, 7);
    g.add(3, 6, 4);
    g.add(4, 5, 9);
    g.add(5, 6, 7);
}
int main()
{
    graph g(7);
    initGraph(g);
    g.printGraph();
    std::cout << "\nPrim's Algorithm\n";
    g.primAlgorithm();
    return 0;
}