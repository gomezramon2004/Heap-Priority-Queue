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