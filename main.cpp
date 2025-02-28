#include <iostream>
#include <list>
#include <string>
using namespace std;

class ElementoPila {
public:
    virtual void muestra() = 0;
};

class Terminal : public ElementoPila {
    string simbolo;
public:
    Terminal(string s) : simbolo(s) {}
    void muestra() override {
        cout << simbolo << " ";
    }
    string getSimbolo() { return simbolo; }
};

class NoTerminal : public ElementoPila {
    string simbolo;
public:
    NoTerminal(string s) : simbolo(s) {}
    void muestra() override {
        cout << simbolo << " ";
    }
};

class Estado : public ElementoPila {
    int numero;
public:
    Estado(int n) : numero(n) {}
    void muestra() override {
        cout << numero << " ";
    }
    int getNumero() { return numero; }
};

class Pila {
    list<ElementoPila*> lista;
public:
    void push(ElementoPila* x) {
        lista.push_front(x);
    }
    ElementoPila* pop() {
        ElementoPila* x = lista.front();
        lista.pop_front();
        return x;
    }
    ElementoPila* top() {
        return lista.front();
    }
    void muestra() {
        cout << "Pila: ";
        for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
            (*it)->muestra();
        }
        cout << endl;
    }
};

void analizarCadena(string entrada) {
    int tablaLR[3][3] = {
        {2, 0, 1},
        {0, -1, 0},
        {0, -2, 0}
    };
    
    Pila pila;
    pila.push(new Estado(0));
    size_t i = 0;
    bool aceptacion = false;
    
    while (!aceptacion && i < entrada.size()) {
        int fila = dynamic_cast<Estado*>(pila.top())->getNumero();
        int columna = (entrada[i] == 'a') ? 0 : (entrada[i] == '$') ? 1 : -1;
        if (columna == -1) {
            cout << "Error: símbolo no reconocido" << endl;
            return;
        }
        int accion = tablaLR[fila][columna];
        
        pila.muestra();
        cout << "Entrada: " << entrada[i] << " | Acción: " << accion << endl;
        
        if (accion > 0) { // Desplazamiento
            pila.push(new Terminal(string(1, entrada[i])));
            pila.push(new Estado(accion));
            i++;
        } else if (accion < 0) { // Reducción
            pila.pop();
            pila.pop();
            pila.push(new NoTerminal("E"));
            pila.push(new Estado(1));
        } else {
            break;
        }
        
        aceptacion = (accion == -1);
    }
    if (aceptacion) cout << "Cadena aceptada" << endl;
    else cout << "Cadena rechazada" << endl;
}

int main() {
    analizarCadena("a$");
    return 0;
}
