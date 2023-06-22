#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using std::cout;

bool precedes(char u, char v, const vector<char>& alphabet, const unordered_map<char, int>& alphabetIndex)
{
    vector<vector<bool>> precedeMatrix(alphabet.size(), vector<bool>(alphabet.size(), false));

    // Construir la matriz de precedencia
    for (int i = 0; i < alphabet.size(); i++)
    {
        for (int j = 0; j < alphabet.size(); j++)
        {
            if (alphabetIndex.at(alphabet[i]) < alphabetIndex.at(alphabet[j]))
            {
                precedeMatrix[i][j] = true;
            }
        }
    }

    // Verificar si u precede a v
    return precedeMatrix[alphabetIndex.at(u)][alphabetIndex.at(v)];
}

int main()
{
    vector<char> alphabet = {'a', 'b', 'c', 'd'};
    unordered_map<char, int> alphabetIndex;
    for (int i = 0; i < alphabet.size(); i++)
    {
        alphabetIndex[alphabet[i]] = i;
    }

    char u = 'b';
    char v = 'd';

    if (precedes(u, v, alphabet, alphabetIndex))
    {
        cout << u << " precede a " << v << " en el orden Φ." << endl;
    }
    else
    {
        cout << u << " no precede a " << v << " en el orden Φ." << endl;
    }

    return 0;
}

/*2. Tenemos un alfabeto Σ = {a,b,c.d} y una relación de orden total Φ definida sobre
los elementos del alfabeto Σ. Sea f(x,y) una función que recibe como entradas
dos elementos de Σ y nos indica si x es el elemento que precede inmediatamente
a y en Φ. Diseñe un algoritmo basado en programación dinámica que, dados dos
elementos cualesquiera del alfabeto, u y v, nos permita determinar si u precede a
v en el orden Φ. */