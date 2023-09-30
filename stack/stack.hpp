#pragma once
#include <stdexcept>

template <class T>
class Node {
    private:
        T data;
        Node<T>* next;
    public:
        Node(T data);
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T>* next);
};

template <class T>
class Stack {
    private:
        int size;
        int MAX_SIZE;
        Node<T>* top;
    public:
        Stack(int MAX_SIZE);
        int getSize();
        T peek();           // Top Function
        void push(T data);  // Create
        void pop();         // Delete
        bool isEmpty();
        bool isFull();
        ~Stack();
};