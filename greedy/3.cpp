#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int id;
    int deadline;
    int benefit;

    Task(int i, int d, int b) : id(i), deadline(d), benefit(b) {}
};

bool compareByBenefit(const Task& t1, const Task& t2) {
    return t1.benefit > t2.benefit;
}

std::vector<int> selectTasks(int n, std::vector<Task>& tasks) {
    std::sort(tasks.begin(), tasks.end(), compareByBenefit);

    std::vector<int> selectedTasks;
    std::vector<bool> slotOccupied(n + 1, false);

    for (const Task& task : tasks) {
        for (int i = task.deadline; i > 0; i--) {
            if (!slotOccupied[i]) {
                selectedTasks.push_back(task.id);
                slotOccupied[i] = true;
                break;
            }
        }
    }

    return selectedTasks;
}

int main() {
    int n = 4;

    std::vector<Task> tasks;
    tasks.emplace_back(1, 2, 50);
    tasks.emplace_back(2, 1, 10);
    tasks.emplace_back(3, 2, 15);
    tasks.emplace_back(4, 1, 30);

    std::vector<int> selectedTasks = selectTasks(n, tasks);

    std::cout << "Conjunto de tareas seleccionadas: ";
    for (int taskId : selectedTasks) {
        std::cout << taskId << " ";
    }
    std::cout << std::endl;

    return 0;
}


/*
3. Tenemos que completar un conjunto de n tareas con plazos límite. Cada una de
las tareas consume la misma cantidad de tiempo (una unidad) y, en un instante
determinado, podemos realizar únicamente una tarea. La tarea i tiene como
plazo límite di
 y produce un beneficio gi
 (gi
 > 0) sólo si la tarea se realiza en un
instante de tiempo t ≤ di
.
a. Diseñe un algoritmo greedy que nos permita seleccionar el conjunto de
tareas que nos asegure el mayor beneficio posible.
b. Aplique su algoritmo a la siguiente instancia del problema:
Tarea i 1 2 3 4
 Beneficio gi
 50 10 15 30
Plazo límite di
 2 1 2 1 
*/