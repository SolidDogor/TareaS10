#include <iostream>
#include <string>

using namespace std;


struct Nodo {
    int prioridad;
    string descripcion;
    string ubicacion;

    int npl;

    Nodo* izq;
    Nodo* der;

    Nodo(int dx, string desc, string ubi) : 
        prioridad(dx), descripcion (desc),
        ubicacion(ubi), npl(0), izq(nullptr), der(nullptr) {} 

};

Nodo* merge(Nodo* heap, Nodo* nuevoNodo){
    if(!heap) return nuevoNodo;
    if(!nuevoNodo) return heap;
    
    if(heap->prioridad > nuevoNodo->prioridad)
        swap(heap, nuevoNodo);
    
    heap->der = merge(heap->der, nuevoNodo);
    
    int nplD = heap->der ? heap->der->npl : -1;
    int nplI = heap->izq ? heap->izq->npl : -1;

    if(nplI < nplD){
        swap(heap->der, heap->izq);
    }
    
    heap->npl = (heap->der ? heap->der->npl : -1) + 1;
    
    return heap;

}

Nodo* insertar(Nodo* heap, int dx, string& desc, string& ubi){
    Nodo* nuevoNodo = new Nodo(dx, desc, ubi);
    return merge(heap, nuevoNodo);
}

void mostrarMin(Nodo* head) {
    if(!head) {
        cout << "No hay incidentes.\n";
        return;
    }
    cout << "Detalles del incidente con mayor prioridad:\n"
        << "Descripcion: " << head->descripcion
        << "\nUbicacion: " << head->ubicacion
        << "\nPrioridad: " << head->prioridad << "\n";
}

Nodo* eliminarMin(Nodo* head){
    if(!head) {
        cout << "No hay incidentes.\n";
        return nullptr;
    }
    Nodo *nuevoNodo = merge(head->izq, head->der);
    cout << "Detalles del incidente atendido:\n"
        << "Descripcion: " << head->descripcion
        << "\nUbicacion: " << head->ubicacion
        << "\nPrioridad: " << head->prioridad << "\n";
    delete head;
    return nuevoNodo;
}

void printHeap(Nodo* heap, int padre){
    if(!heap) {
        cout << "No hay incidentes.\n";
        return;
    }
    cout<<endl<<"Prioridad: "<<heap->prioridad;
    cout<<", Padre" << padre;
    cout<<", NPL: "<<heap->npl;
    cout << "\nDescripcion: " << heap->descripcion;
    cout << "\nUbicacion: " << heap->ubicacion << "\n";

    cout<<endl<<"Hijo Izquierdo: ";
    printHeap(heap->izq, heap->prioridad);
    cout<<endl<<"Hijo Derecho: ";
    printHeap(heap->der, heap->prioridad);
}
