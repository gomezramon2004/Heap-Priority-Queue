#include "stack.hpp"
template <typename T>
class Stack {
    public:
    Node<T>* head;
    Stack() {
        this->head = nullptr;
    }
    void push(T dato) {
        Node<T>* nuevo = new Node<T>(dato);
        if (head == nullptr) {
            head = nuevo;
        } else {
            nuevo->abajo = head;// Nuevo apunta al nodo que está en la cima
            head = nuevo;// La cima de la pila es el nuevo nodo
        }
    }
    void pop() {
        if (head == nullptr) {
            return;
        }

        head = head->abajo; // Mover la cima de la pila al siguiente nodo

    }
    bool isEmpty(){
        return head == nullptr;
    }
    T top(){
        
        return head->dato;
    }
};
