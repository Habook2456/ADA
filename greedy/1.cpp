#include <iostream>
#include <vector>
#include <algorithm>

struct Container {
    int id;
    int weight;

    Container(int i, int w) : id(i), weight(w) {}
};

bool compareByWeight(const Container& c1, const Container& c2) {
    return c1.weight < c2.weight;
}

int maximizeContainersLoaded(int shipCapacity, std::vector<Container>& containers) {
    std::sort(containers.begin(), containers.end(), compareByWeight);

    int totalWeight = 0;
    int loadedContainers = 0;

    for (const Container& container : containers) {
        if (totalWeight + container.weight <= shipCapacity) {
            totalWeight += container.weight;
            loadedContainers++;
        } else {
            break;
        }
    }

    return loadedContainers;
}

int maximizeWeightLoaded(int shipCapacity, std::vector<Container>& containers) {
    std::sort(containers.begin(), containers.end(), compareByWeight);

    int totalWeight = 0;
    int loadedWeight = 0;

    for (const Container& container : containers) {
        if (totalWeight + container.weight <= shipCapacity) {
            totalWeight += container.weight;
            loadedWeight += container.weight;
        } else {
            break;
        }
    }

    return loadedWeight;
}

int main() {
    int shipCapacity;
    std::cout << "Capacidad del buque (en toneladas): ";
    std::cin >> shipCapacity;

    int numContainers;
    std::cout << "Número de contenedores: ";
    std::cin >> numContainers;

    std::vector<Container> containers;
    for (int i = 0; i < numContainers; i++) {
        int containerWeight;
        std::cout << "Peso del contenedor " << i + 1 << " (en toneladas): ";
        std::cin >> containerWeight;
        containers.emplace_back(i + 1, containerWeight);
    }

    int maxContainersLoaded = maximizeContainersLoaded(shipCapacity, containers);
    int maxWeightLoaded = maximizeWeightLoaded(shipCapacity, containers);

    std::cout << "Máximo número de contenedores cargados: " << maxContainersLoaded << std::endl;
    std::cout << "Máximo peso cargado (en toneladas): " << maxWeightLoaded << std::endl;

    return 0;
}

/*
1. Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un
conjunto de contenedores c1, …, cn cuyos pesos respectivos son p1, …, pn
(expresados también en toneladas). Teniendo en cuenta que la capacidad del
buque es menor que la suma total de los pesos de los contenedores:
a. Diseñe un algoritmo que maximice el número de contenedores cargados.
b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas.
*/