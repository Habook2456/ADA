#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Estructura para representar un cliente con sus características
struct Cliente {
    vector<double> caracteristicas;
};

// Función para calcular la distancia entre dos clientes
double calcularDistancia(const Cliente& c1, const Cliente& c2) {
    double distancia = 0.0;
    for (size_t i = 0; i < c1.caracteristicas.size(); ++i) {
        double dif = c1.caracteristicas[i] - c2.caracteristicas[i];
        distancia += dif * dif;
    }
    return sqrt(distancia);
}

// Función para encontrar el cliente más cercano a un grupo dado
int encontrarClienteMasCercano(const vector<Cliente>& clientes, const vector<Cliente>& grupo) {
    int indiceMasCercano = -1;
    double maxDistancia = -1.0;

    for (size_t i = 0; i < clientes.size(); ++i) {
        const Cliente& cliente = clientes[i];
        double minDistancia = numeric_limits<double>::max();

        for (const Cliente& grupoCliente : grupo) {
            double distancia = calcularDistancia(cliente, grupoCliente);
            if (distancia < minDistancia) {
                minDistancia = distancia;
            }
        }

        if (minDistancia > maxDistancia) {
            maxDistancia = minDistancia;
            indiceMasCercano = i;
        }
    }

    return indiceMasCercano;
}

// Función para agrupar clientes en K grupos maximizando la distancia entre ellos
vector<vector<Cliente>> agruparClientes(const vector<Cliente>& clientes, int K) {
    vector<vector<Cliente>> grupos(K);
    int numClientes = clientes.size();

    // Añadir el primer cliente a un grupo inicial
    grupos[0].push_back(clientes[0]);

    // Iterar para añadir el resto de los clientes a los grupos
    for (int i = 1; i < numClientes; ++i) {
        // Encontrar el grupo más cercano al cliente actual
        int indiceGrupoMasCercano = -1;
        double maxDistancia = -1.0;

        for (int j = 0; j < K; ++j) {
            const vector<Cliente>& grupo = grupos[j];
            double distancia = 0.0;

            for (const Cliente& grupoCliente : grupo) {
                distancia += calcularDistancia(clientes[i], grupoCliente);
            }

            distancia /= grupo.size();  // Promedio de las distancias al grupo

            if (distancia > maxDistancia) {
                maxDistancia = distancia;
                indiceGrupoMasCercano = j;
            }
        }

        // Añadir el cliente al grupo más cercano
        grupos[indiceGrupoMasCercano].push_back(clientes[i]);
    }

    return grupos;
}

// Función auxiliar para imprimir los grupos de clientes
void imprimirGrupos(const vector<vector<Cliente>>& grupos) {
    int numGrupos = grupos.size();

    for (int i = 0; i < numGrupos; ++i) {
        cout << "Grupo " << i + 1 << ":" << endl;

        const vector<Cliente>& grupo = grupos[i];
        int numClientes = grupo.size();

        for (int j = 0; j < numClientes; ++j) {
            const Cliente& cliente = grupo[j];
            cout << "Cliente " << j + 1 << ": ";
            for (double caracteristica : cliente.caracteristicas) {
                cout << caracteristica << " ";
            }
            cout << endl;
        }

        cout << endl;
    }
}

int main() {
    // Ejemplo de uso
    vector<Cliente> clientes = {
        {{1.0, 2.0, 3.0}},
        {{4.0, 5.0, 6.0}},
        {{7.0, 8.0, 9.0}},
        {{2.0, 4.0, 6.0}},
        {{1.0, 3.0, 5.0}},
        {{6.0, 4.0, 2.0}}
    };

    int K = 3;  // Número de grupos deseados

    vector<vector<Cliente>> grupos = agruparClientes(clientes, K);
    imprimirGrupos(grupos);

    return 0;
}


/*

9. El departamento de marketing de nuestra empresa desea segmentar nuestro
conjunto de clientes en K grupos para diseñar campañas de marketing dirigidas a
cada grupo por separado. Si suponemos que podemos caracterizar a cada cliente
mediante un vector de características (c1, .., cn) y medir la similitud entre dos
clientes como la inversa de la distancia entre sus vectores de características,
diseñe un algoritmo greedy que nos permita agrupar a nuestros clientes en K
grupos diferentes de tal forma que se maximice la distancia entre clientes de
distintos grupos. */