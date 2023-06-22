#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// Estructura para representar un cliente con su vector de características
struct Customer {
    std::vector<double> features;
};

// Función para calcular la distancia euclídea entre dos vectores de características
double calculateDistance(const std::vector<double>& features1, const std::vector<double>& features2) {
    int n = features1.size();
    double distance = 0.0;

    for (int i = 0; i < n; i++) {
        distance += std::pow(features1[i] - features2[i], 2);
    }

    return std::sqrt(distance);
}

// Función para agrupar clientes maximizando la distancia entre grupos
std::vector<std::vector<Customer>> groupCustomers(const std::vector<Customer>& customers, int K) {
    int n = customers.size();
    int numFeatures = customers[0].features.size();

    // Inicializar K grupos vacíos
    std::vector<std::vector<Customer>> groups(K);

    // Asignar cada cliente al grupo más lejano
    for (const auto& customer : customers) {
        int groupIndex = 0;
        double maxDistance = INT_MIN;

        for (int i = 0; i < K; i++) {
            double groupDistance = 0.0;

            // Calcular la distancia promedio entre el cliente y los clientes del grupo
            if (!groups[i].empty()) {
                for (const auto& c : groups[i]) {
                    groupDistance += calculateDistance(customer.features, c.features);
                }
                groupDistance /= groups[i].size();
            }

            // Actualizar el grupo más lejano
            if (groupDistance > maxDistance) {
                maxDistance = groupDistance;
                groupIndex = i;
            }
        }

        // Asignar el cliente al grupo más lejano
        groups[groupIndex].push_back(customer);
    }

    return groups;
}

int main() {
    // Ejemplo de clientes con sus vectores de características
    std::vector<Customer> customers = {
        {{1.0, 2.0}},
        {{2.0, 3.0}},
        {{5.0, 6.0}},
        {{7.0, 8.0}},
        {{9.0, 10.0}},
        {{12.0, 14.0}}
    };

    int K = 2;  // Número de grupos

    // Agrupar clientes maximizando la distancia entre grupos
    std::vector<std::vector<Customer>> groups = groupCustomers(customers, K);

    // Imprimir los grupos resultantes
    for (int i = 0; i < K; i++) {
        std::cout << "Grupo " << i+1 << ":" << std::endl;
        for (const auto& customer : groups[i]) {
            std::cout << "(";
            for (double feature : customer.features) {
                std::cout << feature << " ";
            }
            std::cout << ")" << std::endl;
        }
        std::cout << std::endl;
    }

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