#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Criterio función
bool Criterio(int nivel, const std::vector<int> &s)
{
    for (int i = 1; i <= nivel - 1; i++)
    {
        if (s[nivel - 1] == s[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Backtracking función
vector<int> Backtracking(std::vector<vector<int>> matrix)
{
    int n = matrix.size();
    int nivel = 1;
    std::vector<int> s(n, 0);
    vector<int> soa(n, 0);
    int bact = 0;      // Valor actual acumulado
    int voa = INT_MIN; // Valor óptimo actual

    while (nivel > 0)
    {
        cout << " -> " << nivel << endl;

        s[nivel - 1] += 1;
        if (s[nivel - 1] == 1)
        {
            bact = bact + matrix[nivel - 1][s[nivel - 1]];
        }
        else
        {
                cout << "[" << nivel - 1 << "][" << s[nivel - 1] << "]" << endl;
                bact = bact + matrix[nivel - 1][s[nivel - 1]] - matrix[nivel - 1][s[nivel - 1] - 1];
        }
        if (((nivel == n) && (Criterio(nivel, s))) && bact > voa)
        {
            voa = bact;
            soa = s;
        }
        if (Criterio(nivel, s))
        {
            nivel++;
        }
        else
        {
            while (!(s[nivel - 1] < n) && nivel > 0)
            {
                bact = bact - matrix[nivel - 1][s[nivel - 1]];
                s[nivel - 1] = 0;
                nivel = nivel - 1;
            }
        }
    }

    return soa;
}

int main()
{

    const int n = 3;
    vector<vector<int>> matrix = {
        {4, 9, 1},
        {7, 2, 3},
        {6, 3, 5}};

    vector<int> soa = Backtracking(matrix);

    std::cout << "Solución óptima encontrada: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << soa[i] << " ";
    }
    std::cout << std::endl;
    // std::cout << "Valor óptimo encontrado: " << voa << std::endl;

    return 0;
}
