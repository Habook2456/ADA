#include <iostream>
#include <vector>
#include <algorithm>

struct Cliente {
    int id;
    int tiempo;
};

bool compararPropinas(const Cliente& c1, const Cliente& c2) {
    return (1.0 / c1.tiempo) > (1.0 / c2.tiempo);
}

void maximizarGananciasCamarero(const std::vector<int>& tiempos) {
    int n = tiempos.size();

    std::vector<Cliente> clientes;
    for (int i = 0; i < n; i++) {
        Cliente cliente;
        cliente.id = i + 1;
        cliente.tiempo = tiempos[i];
        clientes.push_back(cliente);
    }

    // Ordenar los clientes por propina potencial (tiempo de espera inverso)
    std::sort(clientes.begin(), clientes.end(), compararPropinas);

    // Atender a los clientes y calcular las ganancias
    int ganancias = 0;
    for (int i = 0; i < n; i++) {
        int propina = 1.0 / clientes[i].tiempo;
        ganancias += propina;
        std::cout << "Camarero atiende al cliente " << clientes[i].id << " (Tiempo: " << clientes[i].tiempo << ", Propina: " << propina << ")" << std::endl;
    }

    std::cout << "Ganancias totales del camarero: " << ganancias << std::endl;
}

int main() {
    std::vector<int> tiempos = {5, 3, 8, 2, 6};
    maximizarGananciasCamarero(tiempos);

    return 0;
}


/*
5. Supongamos que un único camarero debe atender a n clientes de un restaurante
y atender al cliente i-ésimo requiere un tiempo ti
. La satisfacción de un cliente es
inversamente proporcional a su tiempo de espera y la propina que recibirá el
camarero dependerá de la satisfacción del cliente (si el cliente i espera wi
minutos, la propina que dará al camarero será pi=1/wi).
a. Diseñe un algoritmo greedy para maximizar las ganancias del camarero y
demuestre si el algoritmo diseñado devuelve siempre la solución óptima
[o encuentre un contraejemplo que muestre que no lo hace].
b. Nuestro restaurante toma la decisión de contratar a más camareros para
reducir el tiempo de espera de sus clientes. Modifique el algoritmo
anterior para maximizar las propinas de k camareros. 
*/