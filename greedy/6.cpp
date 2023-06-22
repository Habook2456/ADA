#include <iostream>
#include <vector>
#include <algorithm>

// Estructura para representar una asignación de tarea a trabajador
struct Assignment {
    int worker;
    int task;
    int cost;
};

// Función para asignar tareas a trabajadores utilizando la estrategia aleatoria
std::vector<Assignment> assignTasksRandomly(int n, const std::vector<std::vector<int>>& costs) {
    std::vector<int> tasks(n);
    std::vector<Assignment> assignments;

    // Inicializar el vector de tareas
    for (int i = 0; i < n; i++) {
        tasks[i] = i;
    }

    // Asignar aleatoriamente las tareas a los trabajadores
    std::random_shuffle(tasks.begin(), tasks.end());

    // Construir el vector de asignaciones
    for (int i = 0; i < n; i++) {
        Assignment assignment;
        assignment.worker = i;
        assignment.task = tasks[i];
        assignment.cost = costs[i][tasks[i]];
        assignments.push_back(assignment);
    }

    return assignments;
}

int main() {
    int n = 4; // Número de trabajadores y tareas
    std::vector<std::vector<int>> costs = {{5, 2, 6, 1}, {3, 7, 2, 5}, {1, 3, 9, 4}, {8, 2, 3, 6}};

    // Asignar tareas aleatoriamente a los trabajadores
    std::vector<Assignment> assignments = assignTasksRandomly(n, costs);

    // Imprimir las asignaciones y sus costes
    std::cout << "Asignaciones:\n";
    for (const auto& assignment : assignments) {
        std::cout << "Trabajador " << assignment.worker << " -> Tarea " << assignment.task
                  << " (Coste: " << assignment.cost << ")\n";
    }

    return 0;
}

/*6. Supongamos que disponemos de n trabajadores y n tareas. Sea cij > 0 el coste de
asignarle el trabajo j al trabajador i. Una asignación válida es aquélla en la que a
cada trabajador le corresponde una tarea y cada tarea la realiza un trabajador
diferente. Dada una asignación válida, definimos el coste de dicha asignación
como la suma total de los costes individuales.
a. Diseñe distintas estrategias greedy para asignar tareas.
b. Encuentre contrajemplos que demuestren que ninguna de ellas nos
permite encontrar la solución óptima con un algoritmo greedy. */