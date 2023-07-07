/*a*/
#include <iostream>
#include <vector>
#include <algorithm>

struct Cliente {
    int id;
    int tiempo;
};

bool compararPropina(const Cliente& cliente1, const Cliente& cliente2) {
    return (1.0 / cliente1.tiempo) > (1.0 / cliente2.tiempo);
}

std::vector<int> maximizarGanancias(const std::vector<int>& tiempos) {
    int n = tiempos.size();

    std::vector<Cliente> clientes;
    for (int i = 0; i < n; i++) {
        Cliente cliente;
        cliente.id = i + 1;
        cliente.tiempo = tiempos[i];
        clientes.push_back(cliente);
    }

    std::sort(clientes.begin(), clientes.end(), compararPropina);

    std::vector<int> solucion;
    for (int i = 0; i < n; i++) {
        solucion.push_back(clientes[i].id);
    }

    return solucion;
}

int main() {
    std::vector<int> tiempos = {5, 3, 8, 2, 7};
    std::vector<int> solucion = maximizarGanancias(tiempos);

    std::cout << "Orden óptimo para maximizar las ganancias: ";
    for (int cliente : solucion) {
        std::cout << cliente << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*b*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Cliente {
    int id;
    int tiempo;
};

bool compararPropina(const Cliente& cliente1, const Cliente& cliente2) {
    return (1.0 / cliente1.tiempo) > (1.0 / cliente2.tiempo);
}

std::vector<int> maximizarGanancias(int k, const std::vector<int>& tiempos) {
    int n = tiempos.size();

    std::vector<Cliente> clientes;
    for (int i = 0; i < n; i++) {
        Cliente cliente;
        cliente.id = i + 1;
        cliente.tiempo = tiempos[i];
        clientes.push_back(cliente);
    }

    std::sort(clientes.begin(), clientes.end(), compararPropina);

    std::vector<int> solucion;
    std::priority_queue<int, std::vector<int>, std::greater<int>> camareros;

    for (int i = 0; i < k; i++) {
        camareros.push(0); // Inicializar los tiempos de espera de los camareros en 0
    }

    for (int i = 0; i < n; i++) {
        int tiempoEspera = camareros.top();
        camareros.pop();

        solucion.push_back(clientes[i].id);
        camareros.push(tiempoEspera + clientes[i].tiempo);
    }

    return solucion;
}

int main() {
    int k = 2; // Número de camareros
    std::vector<int> tiempos = {5, 3, 8, 2, 7};
    std::vector<int> solucion = maximizarGanancias(k, tiempos);

    std::cout << "Orden óptimo para maximizar las ganancias con " << k << " camarero(s): ";
    for (int cliente : solucion) {
        std::cout << cliente << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/

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