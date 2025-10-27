<h1 align="center"> Actividad Semana 10 – Estructuras de Datos Avanzadas</h1>

##  Información general
- **Grupo:** 06  
- **Universidad:** Universidad San Ignacio de Loyola  
- **Ciclo:** 2025-II  
- **Lenguaje:** C++

---

## Caso 01: Cuckoo Hashing
**Actividad 01:** Implementar el algoritmo de **Cuckoo Hashing**.

---

## Caso 02: Sistema de Gestión de Emergencias
Una **ciudad inteligente** cuenta con un sistema de gestión de emergencias que debe atender incidentes (accidentes, incendios, robos, etc.) en función de su prioridad.  
Cada incidente tiene:
- Una **prioridad** (entero, donde un valor menor = mayor prioridad)  
- Una **descripción**  
- Una **ubicación**

El sistema debe permitir:
- Insertar nuevos incidentes  
- Atender el incidente de mayor prioridad  
- Fusionar dos zonas de atención (por ejemplo, si dos distritos se combinan temporalmente por falta de recursos)  
- Visualizar el incidente más urgente sin eliminarlo  

Para optimizar estas operaciones, se utilizan **Leftist Heap** y **Skew Heap** como estructuras base.

---

## Funcionalidades del Caso 02

| Funcionalidad | Descripción |
| :------------- | :----------- |
| **Funcionalidad 1** | Inserción de nuevos incidentes con prioridad, descripción y ubicación. |
| **Funcionalidad 2** | Atención del incidente más urgente (mínima prioridad). |
| **Funcionalidad 3** | Visualización del incidente más urgente sin eliminarlo. |
| **Funcionalidad 4** | Fusión de dos zonas mediante la operación `merge()` entre heaps. |

---

## Roles del equipo

| Integrante | Responsabilidad |
| :---------- | :--------------- |
| **Integrante 1 – Modelado de datos y entrada de incidentes** | Diseña la estructura del incidente e implementa la inserción en el heap. |
| **Integrante 2 – Atención de incidentes** | Implementa la extracción del incidente de mayor prioridad y muestra sus detalles. |
| **Integrante 3 – Fusión de zonas** | Implementa la operación de `merge()` entre dos heaps y simula la unión de zonas. |
| **Integrante 4 – Interfaz de simulación** | Desarrolla el menú o interfaz de consola para probar el sistema. |

---

## Evaluación – Leftist Heap

| Criterio | Puntaje |
| :-------- | :-------: |
| Tablero Kanban gestionado correctamente | 4 pts |
| Implementación funcional del heap | 4 pts |
| Repositorio colaborativo completo y organizado | 2 pts |
| **Total** | **10 pts** |

---

## Tecnologías utilizadas
- Lenguaje: **C++**
- Control de versiones: **Git / GitHub**
- Gestión de tareas: **Tablero Kanban (GitHub Projects / Canva)**

---

## Autores

| [<img src="https://avatars.githubusercontent.com/u/150409535?v=4" width=115><br><sub>Alejandro Olivos</sub>](https://github.com/SolidDogor) | [<img src="https://avatars.githubusercontent.com/u/133799723?v=4" width=115><br><sub>Fernando Ramirez</sub>](https://github.com/Fernando270-11) | [<img src="https://avatars.githubusercontent.com/u/159731087?v=4" width=115><br><sub>Josué Gutierrez</sub>](https://github.com/jussepe06) |
| :---: | :---: | :---: |

---

> **Nota:**  
> Las funciones se implementan dentro de una **librería (`.h`)** incluida en el archivo `main.cpp`.
