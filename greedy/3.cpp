#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int id;
    int deadline;
    int profit;
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.profit > task2.profit; // Ordenar en orden no creciente de beneficio
}

vector<Task> selectTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), compareTasks); // Ordenar las tareas por beneficio

    vector<Task> selectedTasks;
    vector<bool> slot(tasks.size(), false); // Marcador para controlar los slots de tiempo ocupados

    for (int i = 0; i < tasks.size(); i++) {
        int currentSlot = min(tasks[i].deadline - 1, static_cast<int>(tasks.size()) - 1); // Encontrar el último slot disponible para la tarea

        while (currentSlot >= 0 && slot[currentSlot]) { // Buscar un slot disponible en orden inverso
            currentSlot--;
        }

        if (currentSlot >= 0) {
            selectedTasks.push_back(tasks[i]); // Agregar la tarea al conjunto seleccionado
            slot[currentSlot] = true; // Marcar el slot como ocupado
        }
    }

    return selectedTasks;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de tareas: ";
    cin >> n;

    vector<Task> tasks(n);

    cout << "Ingrese los beneficios y plazos límite de las tareas:\n";
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        cout << "Tarea " << tasks[i].id << ":\n";
        cout << "Beneficio: ";
        cin >> tasks[i].profit;
        cout << "Plazo límite: ";
        cin >> tasks[i].deadline;
    }

    vector<Task> selectedTasks = selectTasks(tasks);

    cout << "\nEl conjunto de tareas seleccionado es:\n";
    cout << "Tarea\tBeneficio\tPlazo límite\n";
    for (const Task& task : selectedTasks) {
        cout << task.id << "\t" << task.profit << "\t\t" << task.deadline << endl;
    }

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