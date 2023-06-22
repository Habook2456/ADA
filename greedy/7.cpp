#include <iostream>
#include <vector>

// Función para determinar en qué gasolineras debe repostar el autobús
std::vector<int> findRefuelingStations(int n, int fuelCapacity, const std::vector<int>& distances) {
    std::vector<int> refuelingStations;
    int currentFuel = fuelCapacity;

    for (int i = 0; i < n; i++) {
        if (currentFuel < distances[i]) {
            // El autobús necesita repostar en esta gasolinera
            refuelingStations.push_back(i);
            currentFuel = fuelCapacity;
        }
        currentFuel -= distances[i];
    }

    return refuelingStations;
}

int main() {
    int n = 6; // Número de gasolineras en la ruta
    int fuelCapacity = 400; // Capacidad de combustible del autobús en kilómetros
    std::vector<int> distances = {150, 80, 200, 100, 70, 90}; // Distancias entre las gasolineras

    // Determinar en qué gasolineras debe repostar el autobús
    std::vector<int> refuelingStations = findRefuelingStations(n, fuelCapacity, distances);

    // Imprimir las gasolineras en las que debe repostar
    std::cout << "Gasolineras para repostar:\n";
    for (const auto& station : refuelingStations) {
        std::cout << "Gasolinera " << station << "\n";
    }

    return 0;
}
/*7. Un autobús realiza una ruta determinada entre dos ciudades. Con el tanque de
gasolina lleno, el autobús puede recorrer n kilómetros sin parar. El conductor
dispone de un mapa de carreteras que le indica las gasolineras que hay en su
ruta. Para minimizar el tiempo empleado en recorrer su ruta, el conductor desea
pararse a repostar el menor número posible de veces. Diseñe un algoritmo
greedy que determine en qué gasolineras tiene que repostar y demuestre que su
algoritmo encuentra siempre la solución óptima. */