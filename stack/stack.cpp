#include "stack.hpp"

// Implementation of Node Methods

template <class T>
Node<T>::Node(T data) : data(data), next(nullptr) {}        // Constructor

template <class T>
T Node<T>::getData() {                                      // Getters and Setters
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
Stack<T>::Stack(int MAX_SIZE) : size(0), MAX_SIZE(MAX_SIZE), top(nullptr) {}    // Constructor

template <class T>
void Stack<T>::push(T data) {                                                   // Pushing to stack  
    if (isFull()) {
        throw std::runtime_error("ERROR: Stack Overflow");
    }
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(top);
    top = newNode;
    size++;
}

template <class T>
void Stack<T>::pop() {                                                          // Popping from stack         
    if (isEmpty()) {
        throw std::runtime_error("ERROR: Stack is empty");
    }
    Node<T>* temp = top;
    top = top->getNext();
    delete temp;
    size--;
}

template <class T>
T Stack<T>::peek() {                                                            // Peeking at top of stack
    if (!top) {
        throw std::runtime_error("ERROR: Stack is empty");
    }
    return top->getData();
}

template <class T>
int Stack<T>::getSize() {                                                       // Get size of stack            
    return size;
}

template <class T>
bool Stack<T>::isEmpty() {                                                      // Check if stack is empty            
    return top == nullptr;
}

template <class T>                                                              // Check if stack is full     
bool Stack<T>::isFull() {
    return size == MAX_SIZE;
}

template <class T>
Stack<T>::~Stack() {                                                            // Destructor 
    while (top) {
        Node<T>* temp = top;
        top = top->getNext();
        delete temp;
    }
}
