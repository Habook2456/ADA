#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n = 4;
int m = 7;

void backtracking(vector<int> p, vector<int> b)
{
    vector<int> s(n, -1);
    int nivel = 1;
    int voa = INT_MIN;
    vector<int> soa(n, 0);
    int pact = 0;
    int bact = 0;

    while (nivel > 0)
    {
        s[nivel - 1] = s[nivel - 1] + 1;
        pact = pact + p[nivel - 1] * s[nivel - 1];
        bact = bact + p[nivel - 1] * s[nivel - 1];

        if (((nivel == n) && (pact <= m)) && (bact > voa))
        {
            voa = bact;
            soa = s;
        }
        if ((nivel < n) && (pact <= m))
        {
            nivel++;
        }
        else
        {
            while (!(s[nivel - 1] < 1) && (nivel > 0))
            {
                pact = pact - p[nivel - 1] * s[nivel - 1];
                bact = bact - b[nivel - 1] * s[nivel - 1];
                s[nivel - 1] = -1;
                nivel = nivel - 1;
            }
        }
    }

    for(int i = 0; i < soa.size(); i++){
        cout << soa[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> p = {1, 2, 3, 4};
    vector<int> b = {2, 3, 4, 5};

    backtracking(b, p);

    return 1;
}