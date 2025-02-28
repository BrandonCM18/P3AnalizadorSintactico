# Analizador Sintáctico LR(1) con Pila de Objetos

## Descripción
Este proyecto implementa un **Analizador Sintáctico LR(1)** utilizando una **pila de objetos** en lugar de enteros. Se ha desarrollado en **C++** y se ha diseñado para mostrar el estado de la pila en cada paso del análisis, lo que facilita la comprensión del proceso de análisis sintáctico.

## Estructura del Código
El código está compuesto por varias clases:

### 1. **ElementoPila** (Clase base)
   - Clase abstracta que define una estructura común para los elementos de la pila.
   - Métodos:
     - `virtual void muestra() = 0;` → Método virtual puro para imprimir el contenido del elemento.

### 2. **Clases derivadas de `ElementoPila`**
   - **Terminal:** Representa los símbolos terminales de la gramática.
   - **NoTerminal:** Representa los símbolos no terminales de la gramática.
   - **Estado:** Representa los estados de la tabla LR(1).

### 3. **Clase `Pila`**
   - Implementa una pila utilizando una lista (`std::list<ElementoPila*>`).
   - Métodos:
     - `void push(ElementoPila* x);` → Inserta un nuevo elemento en la pila.
     - `ElementoPila* pop();` → Extrae y devuelve el elemento superior de la pila.
     - `ElementoPila* top();` → Devuelve el elemento superior sin extraerlo.
     - `void muestra();` → Imprime el contenido actual de la pila.

### 4. **Función `analizarCadena()`**
   - Implementa el análisis sintáctico LR(1) utilizando la pila.
   - Utiliza una tabla LR(1) predefinida.
   - Procesa una cadena de entrada, mostrando el estado de la pila en cada paso.
   - Determina si la cadena es aceptada o rechazada.

## Compilación y Ejecución
Para compilar el código, usa el siguiente comando en la terminal:
```sh
 g++ main.cpp -o main -std=c++11
```
Para ejecutar el programa:
```sh
 ./main
```

## Ejemplo de Salida
```sh
Pila: 0
Entrada: a | Acción: 2
Pila: 0 a 2
Entrada: $ | Acción: -2
Pila: 0 E 1
Entrada: $ | Acción: -1
Cadena aceptada
```

## Autores
- **Brandon CM**




