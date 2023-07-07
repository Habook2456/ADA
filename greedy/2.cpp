#include <iostream>
#include <vector>
#include <algorithm>

struct Program {
    int id;
    int size;

    Program(int i, int s) : id(i), size(s) {}
};

bool compareBySize(const Program& p1, const Program& p2) {
    return p1.size < p2.size;
}

std::vector<int> maximizeProgramsStored(int diskCapacity, std::vector<Program>& programs) {
    std::sort(programs.begin(), programs.end(), compareBySize);

    int totalSize = 0;
    std::vector<int> storedPrograms;

    for (const Program& program : programs) {
        if (totalSize + program.size <= diskCapacity) {
            totalSize += program.size;
            storedPrograms.push_back(program.id);
        } else {
            break;
        }
    }

    return storedPrograms;
}

std::vector<int> maximizeDiskUtilization(int diskCapacity, std::vector<Program>& programs) {
    std::sort(programs.begin(), programs.end(), compareBySize);

    int totalSize = 0;
    std::vector<int> selectedPrograms;

    for (const Program& program : programs) {
        if (totalSize + program.size <= diskCapacity) {
            totalSize += program.size;
            selectedPrograms.push_back(program.id);
        } else {
            continue;
        }
    }

    return selectedPrograms;
}

int main() {
    int diskCapacity;
    std::cout << "Capacidad del disco (en megabytes): ";
    std::cin >> diskCapacity;

    int numPrograms;
    std::cout << "Número de programas: ";
    std::cin >> numPrograms;

    std::vector<Program> programs;
    for (int i = 0; i < numPrograms; i++) {
        int programSize;
        std::cout << "Tamaño del programa " << i + 1 << " (en megabytes): ";
        std::cin >> programSize;
        programs.emplace_back(i + 1, programSize);
    }

    std::vector<int> maxProgramsStored = maximizeProgramsStored(diskCapacity, programs);
    std::vector<int> maxDiskUtilization = maximizeDiskUtilization(diskCapacity, programs);

    std::cout << "Programas almacenados para maximizar el número de programas: ";
    for (int programId : maxProgramsStored) {
        std::cout << programId << " ";
    }
    std::cout << std::endl;

    std::cout << "Programas seleccionados para maximizar la utilización del disco: ";
    for (int programId : maxDiskUtilization) {
        std::cout << programId << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*2. Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si
 megabytes de espacio y la capacidad del disco es D megabytes,
siendo D < ΣSi
. Resuelva las siguientes cuestiones:
a. Diseñe un algoritmo greedy que maximice el número de programas
almacenados en el disco (existe un algoritmo que proporciona una
solución óptima).
b. Diseñe un algoritmo greedy que intente aprovechar al máximo la
capacidad del disco (demuestre que podemos utilizar un algoritmo
greedy que seleccione los programas por orden no creciente para obtener
la solución exacta o encuentre un contraejemplo de lo contrario). */