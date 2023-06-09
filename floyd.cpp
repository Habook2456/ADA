#include <iostream>
#include <vector>
#include <climits>
#include <limits>
#define INF INT_MAX

void printDistance(int distance)
{
    if (distance == INF)
    {
        std::cout << "INF ";
    }   
    else
    {
        std::cout << distance << "   ";
    }
}

void floyd(std::vector<std::vector<int>> matrix)
{
    int n = matrix.size();

    std::vector<std::vector<int>> distanceMatrix = matrix;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distanceMatrix[i][j] > (distanceMatrix[i][k] + distanceMatrix[k][j]) && (distanceMatrix[k][j] != INF && distanceMatrix[i][k] != INF))
                {
                    distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printDistance(distanceMatrix[i][j]);
        }
        std::cout << std::endl;
    }
}

int main()
{

    std::vector<std::vector<int>> matrix = {{0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

    floyd(matrix);

    return 0;
}