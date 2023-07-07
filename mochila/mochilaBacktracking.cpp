#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n = 5;
int M = 61;

void Backtracking(vector<int> &p, const vector<int> &b)
{
    int nivel = 1;
    vector<int> s(n, -1);
    vector<int> soa(n, 0);
    int voa = INT_MIN;
    int pact = 0;
    int bact = 0;

    while (nivel > 0)
    {
        s[nivel-1] += 1;
        pact += p[nivel-1] * s[nivel-1];
        bact += b[nivel-1] * s[nivel-1];

        if (((nivel == n) && (pact <= M)) && bact > voa)
        {
            voa = bact;
            soa = s;
        }

        if ((nivel < n) && (pact <= M))
        {
            nivel++;
        }
        else
        {
            while (!s[nivel-1] < 1 && nivel > 0)
            {
                pact -= p[nivel-1] * s[nivel-1];
                bact -= b[nivel-1] * s[nivel-1];
                s[nivel-1] = -1;
                nivel -= 1;
            }
        }
    }

    cout << "Items en mochila" << endl;
    for (int i = 0; i < soa.size(); i++)
    {
        if(soa[i] == 1){
            cout << "item " << i << ": peso -> " << p[i] << " - beneficio -> " << b[i] << endl;
        }
    }
    cout << endl;
}

int main()
{

    vector<int> p = {1, 11, 21, 23, 33};
    vector<int> b = {11, 21, 31, 33, 43};

    Backtracking(p, b);

    return 0;
}


