#include "queue.hpp"
#include <algorithm> 

// Implementation of queue Methods

Node::Node(int data) : data(data), left(nullptr), right(nullptr), prev(nullptr) {}


// Implementation of priorityQueue Methods

// Swap
void priorityQueue::swap(Node* a, Node* b) {                                                  
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Heapify up
void priorityQueue::heapifyUp(Node* node) {                                                  
    if (index && arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);
        heapifyUp((index - 1) / 2);
    }
}

// Heapify down
void priorityQueue::heapifyDown(Node* node) {                                                  
    int left = 2 * index + 1, right = 2 * index + 2, smallest = index;
    if (left < currentLength && arr[left] > arr[index]) {
        smallest = left;
    }
    if (right < currentLength && arr[right] > arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyDown(smallest);
    }
}

// Constructor
priorityQueue::priorityQueue() : currentLength(0), front(nullptr), rear(nullptr) {}

// Pushing to priorityQueue
void priorityQueue::push(int data) {                     
    Node* newNode = new Node(data);                 
    
    if (empty()) {
        front = rear = newNode;
    } else {

        if (!front->left) {
            front->left = newNode;
            newNode->prev = rear;
            rear = newNode;
        } else if (!front->right) {
            front->right = newNode;
            newNode->prev = rear->prev;
            rear = newNode;
        } else {

        }
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
