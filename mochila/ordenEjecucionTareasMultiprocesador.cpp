#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar una tarea con su tiempo de ejecución
struct Task {
    int id;
    int time;

    Task(int _id, int _time) : id(_id), time(_time) {}
};

// Estructura para representar un procesador con su identificador y el tiempo total de ejecución
struct Processor {
    int id;
    int totalTime;

    Processor(int _id) : id(_id), totalTime(0) {}
};

// Función de comparación para ordenar los procesadores en orden ascendente según su tiempo total de ejecución
bool compareProcessors(const Processor& proc1, const Processor& proc2) {
    return proc1.totalTime < proc2.totalTime;
}

// Función para asignar las tareas a los procesadores y minimizar el tiempo total de ejecución
std::vector<Processor> minimizeTime(const std::vector<int>& executionTimes, int numProcessors) {
    int n = executionTimes.size();
    std::vector<Task> tasks;
    std::vector<Processor> processors;

    // Crear vector de tareas
    for (int i = 0; i < n; i++) {
        tasks.push_back(Task(i + 1, executionTimes[i]));
    }

    // Crear vector de procesadores
    for (int i = 0; i < numProcessors; i++) {
        processors.push_back(Processor(i + 1));
    }

    // Asignar tareas a los procesadores
    for (const Task& task : tasks) {
        // Ordenar los procesadores en orden ascendente según su tiempo total de ejecución
        std::sort(processors.begin(), processors.end(), compareProcessors);

        // Asignar la tarea al procesador con el menor tiempo total de ejecución
        processors[0].totalTime += task.time;
    }

    return processors;
}

int main() {
    std::vector<int> executionTimes = {7, 1, 6, 2, 3, 4, 2, 5, 7};
    int numProcessors = 4;

    std::vector<Processor> schedule = minimizeTime(executionTimes, numProcessors);

    // Ordenar los procesadores en orden ascendente según su tiempo total de ejecución
    std::sort(schedule.begin(), schedule.end(), compareProcessors);

    std::cout << "Asignación de tareas a los procesadores:" << std::endl;
    for (const Processor& proc : schedule) {
        std::cout << "Procesador " << proc.id << ": Tiempo total = " << proc.totalTime << std::endl;
    }

    return 0;
}
/*
3.3 Construir un algoritmo voraz para resolver el problema de la minimización del
tiempo en el sistema pero con varios procesadores. Tenemos un conjunto de n
tareas, cada una de las cuales tarda un tiempo ti
, y disponemos de m procesadores
para ejecutar las tareas. Las tareas se ejecutan secuencialmente, es decir, no se
pueden partir. ¿Cuál es el orden de complejidad del algoritmo? Mostrar la
ejecución para un ejemplo con m=4 y n=9, t=(7, 1, 6, 2, 3, 4, 2, 5, 7).
*/