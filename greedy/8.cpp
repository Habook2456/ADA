#include <iostream>
#include <vector>
#include <cmath>

// Estructura para representar una ciudad con sus coordenadas (x, y)
struct City {
    int x;
    int y;
};

// Función para calcular la distancia euclídea entre dos ciudades
double calculateDistance(const City& city1, const City& city2) {
    int dx = city1.x - city2.x;
    int dy = city1.y - city2.y;
    return std::sqrt(dx*dx + dy*dy);
}

// Función para interconectar ciudades minimizando el coste de la red
double minimizeCost(const std::vector<City>& cities) {
    int n = cities.size();
    double totalCost = 0.0;

    for (int i = 0; i < n - 1; i++) {
        const City& currentCity = cities[i];
        double minDistance = calculateDistance(currentCity, cities[i+1]);

        for (int j = i + 2; j < n; j++) {
            double distance = calculateDistance(currentCity, cities[j]);
            if (distance < minDistance) {
                minDistance = distance;
            }
        }

        totalCost += minDistance;
    }

    return totalCost;
}

int main() {
    // Ejemplo de ciudades con sus coordenadas (x, y)
    std::vector<City> cities = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};

    // Calcular el coste mínimo de interconexión
    double cost = minimizeCost(cities);

    // Imprimir el coste mínimo
    std::cout << "Coste mínimo de interconexión: " << cost << std::endl;

    return 0;
}

/*8. Supongamos que el coste de tender una red de fibra óptica entre dos ciudades es
proporcional a la distancia euclídea entre ellas.
a. Diseñe un algoritmo que permita interconectar un conjunto de ciudades
minimizando el coste de la red de interconexión.
b. Busque un ejemplo en el que se demuestre que puede resultar más
económico instalar una centralita entre ciudades que utilizar solamente
conexiones directas entre ciudades. */