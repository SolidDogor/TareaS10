#include <iostream>
#include <string>
#include "leftist_heap.h"  // Archivo con la implementación del heap sesgado
using namespace std;

int main() {
    Nodo* heap = nullptr;
    int opcion;

    do {
        cout << "\n===== SISTEMA DE GESTIÓN DE EMERGENCIAS =====\n";
        cout << "1. Registrar nuevo incidente\n";
        cout << "2. Ver incidente más urgente\n";
        cout << "3. Atender incidente más urgente\n";
        cout << "4. Mostrar todos los incidentes (estructura)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int prioridad;
            string desc, ubi;

            cout << "Prioridad (menor = más urgente): ";
            cin >> prioridad;
            cin.ignore();

            cout << "Descripción del incidente: ";
            getline(cin, desc);
            cout << "Ubicación: ";
            getline(cin, ubi);

            heap = insertar(heap, prioridad, desc, ubi);
            cout << "Incidente agregado correctamente.\n";
        }
        else if (opcion == 2) {
            mostrarMin(heap);
        }
        else if (opcion == 3) {
            heap = eliminarMin(heap);
        }
        else if (opcion == 4) {
            if (!heap) cout << " No hay incidentes para mostrar.\n";
            else {
                cout << "\n ESTRUCTURA DEL HEAP:\n";
                printHeap(heap);
                cout << endl;
            }
        }
        else if (opcion == 0) {
            cout << " Saliendo del sistema...\n";
        }
        else {
            cout << "Opción inválida. Intente nuevamente.\n";
        }

    } while (opcion != 0);

    return 0;
}
