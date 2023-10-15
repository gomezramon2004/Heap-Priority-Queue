#include "queue.hpp"
#include <algorithm> 
#include <iostream>

// Implementation of queue Methods

Node::Node(int data) : data(data), left(nullptr), right(nullptr), prev(nullptr) {}


// Implementation of priorityQueue Methods

// Check current level
void priorityQueue::upgradeCurrentLevel(int& currentLevel, int& currentLength) {                                                  
    if (currentLength == ((2 ^ (currentLevel+1)) - 1)) ++currentLevel;
}


// Preorder
void priorityQueue::searchByPreOrder(Node* node, Node* newNode, bool& flag, int& level) {  
    if (flag || level == currentLevel) {
        --level;
        return;
    }  

    if (node->left && node->right) {
        ++level;
        searchByPreOrder(node->left, newNode, flag, level);
        searchByPreOrder(node->right, newNode, flag, level);
    } else if (!node->left) {
        node->left = newNode;
        newNode->prev = node;
        rear = newNode;
        flag = true;
    } else if (!node->right) {
        node->right = newNode;
        newNode->prev = node;
        rear = newNode;
        flag = true;
    }
}

// Swap
void priorityQueue::swap(Node* a, Node* b) {                                                  
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Heapify up
void priorityQueue::heapifyUp(Node* node) {  
    if (node->prev && node->data > node->prev->data) {
        swap(node, node->prev);
        heapifyUp(node->prev);
    }
}

// Heapify down
void priorityQueue::heapifyDown(Node* node) {                                                  

}

// Constructor
priorityQueue::priorityQueue() : currentLength(0), currentLevel(-1), front(nullptr), rear(nullptr) {}

// Pushing to priorityQueue
void priorityQueue::push(int data) {                     
    Node* newNode = new Node(data);                 
    
    if (empty()) {
        front = rear = newNode;
        ++currentLevel;
    } else {
        int level = 0;
        bool addedElement = false;  // Initialize the flag
        upgradeCurrentLevel(currentLevel, currentLength);
        searchByPreOrder(front, newNode, addedElement, level);
        heapifyUp(rear);
    }
    ++currentLength;
}

// Popping from priorityQueue
void priorityQueue::pop() {                                                                  
    if (empty()) {
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
    swap(front, rear);
    heapifyDown(front);
    --currentLength;
}

// Peeking at top of priorityQueue
int priorityQueue::top() {                                                          
    if (empty()) { 
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
    return front->data;
}

// Check if priorityQueue is empty 
bool priorityQueue::empty() {                                                                  
    return !front;
}

// Get size of priorityQueue
int priorityQueue::size() {                                                                     
    return currentLength;
}
