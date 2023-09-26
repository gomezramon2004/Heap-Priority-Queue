#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T dato;
    Node* abajo;

    Node(T dato) {
        this->dato = dato;
        this->abajo = nullptr;
    }
};

template <typename T>
class Lista {
private:
    Node<T>* head;

public:
    Lista() {
        this->head = nullptr;
    }

    void agregarInicio(T dato) {
        Node<T>* nuevo = new Node<T>(dato);
        if (head == nullptr) {
            head = nuevo;
        } else {
            nuevo->abajo = head;
            head = nuevo;
        }
    }

    void agregarFinal(T dato) {
        Node<T>* nuevo = new Node<T>(dato);
        if (head == nullptr) {
            head = nuevo;
        } else {
            Node<T>* temp = head;
            while (temp->abajo != nullptr) {
                temp = temp->abajo;
            }
            temp->abajo = nuevo;
        }
    }

void agregaEnMedio(T dato, int posicion) {
    Node<T>* nuevo = new Node<T>(dato);
    if (posicion == 0) {
        nuevo->abajo = head;
        head = nuevo;
        return;
    }
    Node<T>* temp = head;
    int contador = 0;
    while (temp != nullptr) {
        if (contador == posicion - 1) {
            nuevo->abajo = temp->abajo;
            temp->abajo = nuevo;
            return;
        }
        temp = temp->abajo;
        contador++;
    }
}
int buscar(T dato) {
    Node<T>* temp = head;
    int contador = 0;
    while (temp != nullptr) {
        if (temp->dato == dato) {
            return contador;
        }
        temp = temp->abajo;
        contador++;
    }
    std::cout << "Dato no encontrado." << std::endl;
    return -1;
}
void cambiar(T dato, T nuevo) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        if (temp->dato == dato) {
            temp->dato = nuevo;
            return;
        }
        temp = temp->abajo;
    }
    std::cout << "Dato no encontrado, no se realizó ningún cambio." << std::endl;
}

void eliminar(T dato) {
    if (head == nullptr) {
        std::cout << "Lista vacía" << std::endl;
        return;
    }
    if (head->dato == dato) {
        head = head->abajo;
        return;
    }
    Node<T>* temp = head;
    while (temp->abajo != nullptr) {
        if (temp->abajo->dato == dato) {
            temp->abajo = temp->abajo->abajo;
            return;
        }
        temp = temp->abajo;
    }
    std::cout << "Dato no encontrado" << std::endl;
}

    void imprimir() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->dato << endl;
            temp = temp->abajo;
        }
    }
};

int main() {
    // Caso de prueba 1: Números enteros
    Lista<int> lista1;

    lista1.agregarInicio(1);
    lista1.agregarInicio(2);
    lista1.agregarFinal(3);
    lista1.agregarFinal(4);
    lista1.agregaEnMedio(5, 2);

    cout << "Lista de enteros: "<<endl;
    lista1.imprimir();

    int posicion1 = lista1.buscar(3);
    if (posicion1 != -1) {
        cout << "El elemento 3 se encuentra en la posición " << posicion1 << endl;
    } else {
        cout << "El elemento 3 no se encuentra en la lista." << endl;
    }

    lista1.cambiar(2, 6);
    cout << "Lista de enteros después de cambiar el elemento 2 por 6: "<<endl;
    lista1.imprimir();

    lista1.eliminar(5);
    cout << "Lista de enteros después de eliminar el elemento 5: "<<endl;
    lista1.imprimir();
    cout<<"--------------------------"<<endl;

    // Caso de prueba 2: Cadenas de texto
    Lista<string> lista2;

    lista2.agregarInicio("Manzana");
    lista2.agregarInicio("Banana");
    lista2.agregarFinal("Cereza");
    lista2.agregarFinal("Damasco");
    lista2.agregaEnMedio("Fresa", 2);

    cout << "Lista de cadenas de texto: "<<endl;
    lista2.imprimir();

    int posicion2 = lista2.buscar("Cereza");
    if (posicion2 != -1) {
        cout << "La cadena 'Cereza' se encuentra en la posición " << posicion2 << endl;
    } else {
        cout << "La cadena 'Cereza' no se encuentra en la lista." << endl;
    }

    lista2.cambiar("Banana", "Kiwi");
    cout << "Lista de cadenas de texto después de cambiar 'Banana' por 'Kiwi': "<<endl;
    lista2.imprimir();

    lista2.eliminar("Damasco");
    cout << "Lista de cadenas de texto después de eliminar 'Damasco': "<<endl;
    lista2.imprimir();
    cout<<"--------------------------"<<endl;

    // Caso de prueba 3: Números decimales
    Lista<double> lista3;

    lista3.agregarInicio(1.5);
    lista3.agregarInicio(2.3);
    lista3.agregarFinal(3.7);
    lista3.agregarFinal(4.2);
    lista3.agregaEnMedio(5.1, 2);

    cout << "Lista de números decimales: " << endl;
    lista3.imprimir();

    int posicion = lista3.buscar(3.7);
    if (posicion != -1) {
        cout << "El elemento 3.7 se encuentra en la posición " << posicion << endl;
    } else {
        cout << "El elemento 3.7 no se encuentra en la lista." << endl;
    }

    lista3.cambiar(2.3, 6.0);
    cout << "Lista después de cambiar el elemento 2.3 por 6.0: " << endl;
    lista3.imprimir();

    lista3.eliminar(5.1);
    cout << "Lista después de eliminar el elemento 5.1: " << endl;
    lista3.imprimir();
    cout<<"--------------------------"<<endl;

    // Caso de prueba 4: Buscar un dato que no esta en la lista
    Lista<int> lista4;

    lista4.agregarInicio(1);
    lista4.agregarInicio(2);
    lista4.agregarFinal(3);

    cout << "Lista de enteros: "<<endl;
    lista4.imprimir();

    posicion = lista4.buscar(4);
    if (posicion != -1) {
        cout << "El elemento 4 se encuentra en la posición " << posicion << endl;
    } else {
        cout << "El elemento 4 no se encuentra en la lista." << endl;
    }

    return 0;

}