#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using std::cout;

vector<int> mochilaGreedy(vector<int> peso, vector<int> beneficio, int pesoMaximoMochila)
{

    int objetos = peso.size();
    vector<int> solucion(objetos, 0);
    int pesoActual = 0;
    int objetoActual = 0;

    for (int i = 0; i < objetos; i++)
    {
        while (pesoActual < pesoMaximoMochila)
        {
            // eleccion mejor beneficio
            // auto beneficioActualIter = max_element(beneficio.begin(), beneficio.end());
            // int pos = distance(beneficio.begin(), beneficioActualIter);
            // eleccion menos pesado
            auto pesoActualIter = min_element(peso.begin(), peso.end());
            int pos = distance(peso.begin(), pesoActualIter);

            if (pesoActual + peso[pos] <= pesoMaximoMochila)
            {
                solucion[pos] = 1;
                pesoActual += peso[pos];
            }
            else
            {
                solucion[pos] = (pesoMaximoMochila - pesoActual) / peso[pos];
                pesoActual = pesoMaximoMochila;
            }
            peso[pos] = INT_MAX;      // modificar
            beneficio[pos] = INT_MAX; // modificar
        }
    }

    return solucion;
}

int main()
{
    vector<int> peso = {1, 2, 5, 6, 7};
    vector<int> beneficio = {1, 6, 18, 22, 28};
    int pesoMaximoMochila = 13;

    vector<int> solucion = mochilaGreedy(peso, beneficio, pesoMaximoMochila);

    cout << "Items en Mochila" << endl;
    for (int i = 0; i < solucion.size(); i++)
    {
        if (solucion[i] == 1)
        {
            cout << "item " << i + 1 << ": peso -> " << peso[i] << " | beneficio -> " << beneficio[i] << endl;
        }
    }

    return 0;
}