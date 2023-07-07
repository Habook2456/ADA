#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Estructura para representar una tarea con su tiempo de ejecución y plazo
struct Task {
    int id;
    int time;
    int deadline;

    Task(int _id, int _time, int _deadline) : id(_id), time(_time), deadline(_deadline) {}
};

// Función de comparación para ordenar las tareas en orden ascendente según su tiempo de ejecución
bool compareTasks(const Task& task1, const Task& task2) {
    return task1.time < task2.time;
}

// Función para planificar las tareas con plazo fijo
std::vector<int> scheduleTasks(const std::vector<int>& executionTimes, const std::vector<int>& deadlines) {
    int n = executionTimes.size();
    std::vector<Task> tasks;
    std::vector<int> schedule(n, -1);  // Vector para almacenar la planificación de las tareas

    // Crear vector de tareas
    for (int i = 0; i < n; i++) {
        tasks.push_back(Task(i + 1, executionTimes[i], deadlines[i]));
    }

    // Ordenar las tareas en orden ascendente según su tiempo de ejecución
    std::sort(tasks.begin(), tasks.end(), compareTasks);

    // Asignar las tareas a los procesadores
    for (const Task& task : tasks) {
        int deadline = task.deadline;

        // Buscar el procesador disponible más cercano al plazo establecido
        int processor = -1;
        int minDeadlineDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (schedule[i] == -1) {
                int deadlineDiff = std::abs(deadline - (i + 1));
                if (deadlineDiff < minDeadlineDiff) {
                    processor = i;
                    minDeadlineDiff = deadlineDiff;
                }
            }
        }

        // Asignar la tarea al procesador correspondiente
        if (processor != -1) {
            schedule[processor] = task.id;
        }
    }

    return schedule;
}

int main() {
    std::vector<int> executionTimes = {10, 20, 8, 15, 30, 10, 5, 10, 2, 9};
    std::vector<int> deadlines = {1, 4, 4, 1, 4, 2, 3, 4, 5, 4};

    std::vector<int> schedule = scheduleTasks(executionTimes, deadlines);

    std::cout << "Planificación de tareas:" << std::endl;
    for (int i = 0; i < schedule.size(); i++) {
        if (schedule[i] != -1) {
            std::cout << "Tarea " << schedule[i] << " asignada al procesador " << i + 1 << std::endl;
        }
    }

    return 0;
}

/*
Ejecutar el algoritmo para planificación de tareas con plazo fijo, visto en clase,
sobre el siguiente conjunto de tareas:
n= 10
g = (10, 20, 8, 15, 30, 10, 5, 10, 2, 9)
d = ( 1, 4, 4, 1, 4, 2, 3, 4, 5, 4)
*/