#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Función para encontrar la asignación óptima utilizando el algoritmo greedy
vector<pair<int, int>> asignacionGreedy(vector<vector<int>>& costos) {
    int n = costos.size();
    vector<bool> trabajadorAsignado(n, false); // Marcar si el trabajador i ha sido asignado
    vector<pair<int, int>> asignacion; // Lista de pares (trabajador, tarea) asignados

    // Iterar sobre todas las tareas
    for (int tarea = 0; tarea < n; tarea++) {
        int minCosto = INT_MAX;
        int mejorTrabajador;

        // Encontrar el trabajador disponible con el menor costo para la tarea actual
        for (int trabajador = 0; trabajador < n; trabajador++) {
            if (!trabajadorAsignado[trabajador] && costos[trabajador][tarea] < minCosto) {
                minCosto = costos[trabajador][tarea];
                mejorTrabajador = trabajador;
            }
        }

        // Asignar la tarea al trabajador seleccionado
        asignacion.push_back(make_pair(mejorTrabajador, tarea));
        trabajadorAsignado[mejorTrabajador] = true;
    }

    return asignacion;
}

// Función auxiliar para imprimir la asignación
void imprimirAsignacion(const vector<pair<int, int>>& asignacion) {
    for (const auto& par : asignacion) {
        cout << "Trabajador " << par.first << " -> Tarea " << par.second << endl;
    }
}

int main() {
    int n = 3;

    vector<vector<int>> costos = {{4,1,6},{7,4,2},{3,6,1}};


    vector<pair<int, int>> asignacion = asignacionGreedy(costos);

    cout << "Asignación óptima:" << endl;
    imprimirAsignacion(asignacion);

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