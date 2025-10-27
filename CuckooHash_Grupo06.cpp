#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int tableSize = 10;
const int MAX_RECURSION = 20;

int hash1(const string &key) {
    int h = 0;
    for (char c : key) h = (h * 37 + c) % tableSize;
    return h;
}

int hash2(const string &key) {
    int h = 0;
    for (char c : key) h = (h * 13 + c) % tableSize;
    return h;
}

bool insertarRecursivo(vector<string> &t1, vector<string> &t2, string key, int tabla, int profundidad = 0) {
    if (profundidad > MAX_RECURSION) {
        cout << "Se ha alcanzado el limite, debe rehashear.\n";
        return false;
    }

    int pos = (tabla == 1 ? hash1(key) : hash2(key));
    vector<string> &t = (tabla == 1 ? t1 : t2);

    if (t[pos].empty()) {
        t[pos] = key;
        cout << "\"" << key << "\" guardado en tabla " << tabla << "[" << pos << "]\n";
        return true;
    } else {
        //Hacer intercambio
        cout << "Colision en tabla " << tabla << "[" << pos << "] -> pateamos \"" << t[pos] << "\"\n";
        string desplazado = t[pos];
        t[pos] = key;
        //Insertar en otra tabla de manera recursiva
        return insertarRecursivo(t1, t2, desplazado, tabla == 1 ? 2 : 1, profundidad + 1);
    }
}

int main() {
    
    vector<string> t1(tableSize);
    vector<string> t2(tableSize);

    int q, i = 1;
    cout << "Cuantos nombres desea ingresar?"; cin >> q;
    string nombre;
    while (i <= q) {
        cout << "Digite el nombre #" << i << ": ";
        cin >> nombre;
        insertarRecursivo(t1, t2, nombre, 1);
        i++;
    }

    cout << "\n=== TABLA 1 ===\n";
    for (int i = 0; i < tableSize; i++) {
        cout << i << ": " << (t1[i].empty() ? "[vacio]" : t1[i]) << "\n";
    }

    cout << "\n=== TABLA 2 ===\n";
    for (int i = 0; i < tableSize; i++) {
        cout << i << ": " << (t2[i].empty() ? "[vacio]" : t2[i]) << "\n";
    }
}
