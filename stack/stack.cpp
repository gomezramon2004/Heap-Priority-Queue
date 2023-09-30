#include "stack.hpp"

// Implementation of Node Methods

template <class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template <class T>
T Node<T>::getData() {
    return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <class T>
void Node<T>::setData(T data) {
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}


// Implementation of Stack Methods
template <class T>
Stack<T>::Stack(int MAX_SIZE) : size(0), MAX_SIZE(MAX_SIZE), top(nullptr) {}

template <class T>
T Stack<T>::getTop() {
    if (!top) {
        throw std::runtime_error("ERROR: Stack is empty");
    }
    return top->getData();
}

template <class T>
int Stack<T>::getSize() {
    return size;
}

template <class T>
void Stack<T>::push(T data) {
    if (isFull()) {
        throw std::runtime_error("ERROR: Stack Overflow");
    }
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(top);
    top = newNode;
    size++;
}

template <class T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("ERROR: Stack is empty");
    }
    Node<T>* temp = top;
    top = top->getNext();
    delete temp;
    size--;
}

template <class T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template <class T>
bool Stack<T>::isFull() {
    return size == MAX_SIZE;
}

template <class T>
Stack<T>::~Stack() {
    while (top) {
        Node<T>* temp = top;
        top = top->getNext();
        delete temp;
    }
}
