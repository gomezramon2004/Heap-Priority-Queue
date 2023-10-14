#pragma once
#include <stdexcept>

class Node {
    public:
        int data;
        Node* next;
        Node(int data);
};

class Queue {
    private:
        int length;
        Node* front;
        Node* rear;
        void swap();
    public:
        Queue();
        void push(int data);
        void pop();
        int top(); 
        bool empty();
        int size();
        ~Queue();
};