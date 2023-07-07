#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar una tarea con su tiempo de ejecución
struct Task {
    int id;
    int time;

    Task(int _id, int _time) : id(_id), time(_time) {}
};

// Función de comparación para ordenar las tareas en orden ascendente según su tiempo de ejecución
bool compareTasks(const Task& task1, const Task& task2) {
    return task1.time < task2.time;
}

// Función para calcular el tiempo medio de finalización dado un orden de ejecución de tareas
double calculateAverageCompletionTime(const std::vector<Task>& tasks) {
    int n = tasks.size();
    double totalTime = 0.0;
    double averageTime = 0.0;

    for (int i = 0; i < n; i++) {
        totalTime += tasks[i].time;
        averageTime += totalTime;
    }

    averageTime /= n;
    return averageTime;
}

// Función principal para resolver el problema de minimización del tiempo en el sistema
std::vector<Task> minimizeTime(const std::vector<int>& executionTimes) {
    int n = executionTimes.size();
    std::vector<Task> tasks;

    // Crear vector de tareas
    for (int i = 0; i < n; i++) {
        tasks.push_back(Task(i + 1, executionTimes[i]));
    }

    // Ordenar las tareas en orden ascendente según su tiempo de ejecución
    std::sort(tasks.begin(), tasks.end(), compareTasks);

    return tasks;
}

int main() {
    std::vector<int> executionTimes = {4, 10, 2, 20};
    std::vector<Task> schedule = minimizeTime(executionTimes);

    std::cout << "Orden de ejecucion optimo:" << std::endl;
    for (const Task& task : schedule) {
        std::cout << "Tarea " << task.id << " (tiempo: " << task.time << ")" << std::endl;
    }

    std::cout << "Tiempo medio de finalizacion: " << calculateAverageCompletionTime(schedule) << std::endl;

    return 0;
}

/*
3.2 Se define el problema de la minimización del tiempo en el sistema de la
siguiente manera. Tenemos un conjunto de n tareas, cada una de las cuales tarda
un tiempo predefinido ti
, y un procesador donde se ejecutan las tareas. El objetivo
es dar una planificación de las tareas (un orden de ejecución de las mismas) de
manera que se minimice el tiempo medio de finalización. El tiempo de
finalización de una tarea es el tiempo que transcurre entre el instante inicial
(instante 0) y el momento en el que concluye una tarea. Construir un algoritmo
voraz para resolver el problema de la minimización del tiempo en el sistema.
Mostrar la ejecución para el ejemplo, n= 4, t= (4, 10, 2, 20). Demostrar que el
algoritmo voraz construido es óptimo.

*/