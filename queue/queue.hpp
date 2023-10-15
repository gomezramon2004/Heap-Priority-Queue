#pragma once

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node *prev;
        Node(int data);
};

class priorityQueue {
    private:
        int currentLength;
        int currentLevel;
        Node* front;
        Node* rear;
        void upgradeCurrentLevel(int& currentLevel, int& currentLength);
        void searchByPreOrder(Node* node, Node* newNode, bool& flag, int& level);
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