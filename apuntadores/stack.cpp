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
int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.isEmpty() << endl;
    return 0;
}