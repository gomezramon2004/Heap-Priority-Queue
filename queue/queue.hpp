#pragma once

class Node {
    public:
        int data;
        Node *left;
        Node *right
        Node *prev;
        Node(int data);
};

class priorityQueue {
    private:
        int currentLength;
        Node* front;
        Node* rear;
        void swap(Node* a, Node* b);
        void heapifyUp(Node* node);
        void heapifyDown(Node* node);
    public:
        priorityQueue();
        void push(int data);
        void pop();
        int top(); 
        bool empty();
        bool full();
        int size();
};