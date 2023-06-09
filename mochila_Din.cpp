#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using std::cout;

void printTable(vector<vector<int>> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<int, int>> makeObjetos(vector<int> a, vector<int> b)
{
    vector<pair<int, int>> objetos;
    if (a.size() != b.size())
        return vector<pair<int, int>>();

    for (int i = 0; i < a.size(); i++)
    {
        objetos.push_back(make_pair(a[i], b[i]));
    }
    return objetos;
}

void knapsack(vector<pair<int, int>> objects, int maxWeight)
{
    int objectsSize = objects.size();
    vector<int> solution(objectsSize, 0);
    vector<vector<int>> knapsackTable(objectsSize + 1, vector<int>(maxWeight + 1, 0));

    for (int i = 1; i <= objectsSize; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (j - objects[i - 1].first < 0)
            {
                knapsackTable[i][j] = knapsackTable[i - 1][j];
            }
            else
            {
                knapsackTable[i][j] = max(knapsackTable[i - 1][j], objects[i - 1].second + knapsackTable[i - 1][j - objects[i - 1].first]);
            }
        }
    }
    cout << "knapsack solutions table" << endl;
    printTable(knapsackTable);

    int j = maxWeight;
    for (int i = objectsSize; i >= 1; i--)
    {
        if (knapsackTable[i][j] == knapsackTable[i - 1][j])
            solution[i - 1] = 0;
        else
        {
            solution[i - 1] = 1;
            j -= objects[i - 1].first;
        }
    }

    cout << "Items en Mochila" << endl;
    for(int i = 0; i < solution.size(); i++){
        if(solution[i] == 1){
            cout << "item " << i+1 << ": peso -> " << objects[i].first << " | beneficio -> " << objects[i].second << endl;         
        }
    }
}

int main()
{
    vector<int> peso = {2, 3, 4};
    vector<int> beneficio = {1, 2, 5};
    vector<pair<int, int>> objetos = makeObjetos(peso, beneficio);
    int pesoMaximo = 6;

    knapsack(objetos, pesoMaximo);
    

    return 0;
}