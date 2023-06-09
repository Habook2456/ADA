#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using std::cout;

int main()
{
    vector<int> peso = {2,190};
    vector<int> beneficio = {1,100};
    int pesoMaximoMochila = 100;
    int objetos = 2;
    vector<int> x(objetos, 0);
    int pesoActual = 0;
    int objetoActual = 0;

    for (int i = 0; i < objetos; i++)
    {
        // x[i] = 0;
        while (pesoActual < pesoMaximoMochila)
        {
            // eleccion mejor beneficio
            // auto beneficioActualIter = max_element(beneficio.begin(), beneficio.end());
            // int pos = distance(beneficio.begin(), beneficioActualIter);
            // eleccion menos pesado
            auto pesoActualIter = min_element(peso.begin(), peso.end());
            int pos = distance(peso.begin(), pesoActualIter);

            cout << "pos: " << pos << endl;
            if (pesoActual + peso[pos] <= pesoMaximoMochila)
            {
                x[pos] = 1;
                pesoActual += peso[pos];
            }
            else
            {
                x[pos] = (pesoMaximoMochila - pesoActual) / peso[pos];
                pesoActual = pesoMaximoMochila;
            }
            cout << pesoActual << endl;
            peso[pos] = INT_MAX;
            beneficio[pos] = INT_MAX;
        }
    }

    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}