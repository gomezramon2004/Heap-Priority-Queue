#include "queue.hpp"

// Implementation of priorityQueue Methods

// Swap
void priorityQueue::swap(int &a, int &b) {                                                  
    int temp = a;
    a = b;
    b = temp;
}

// Heapify up
void priorityQueue::heapifyUp(int index) {                                                  
    if (index && arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);
        heapifyUp((index - 1) / 2);
    }
}

// Heapify down
void priorityQueue::heapifyDown(int index) {                                                  
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
priorityQueue::priorityQueue(int MAX_LENGTH) : currentLength(0), MAX_LENGTH(MAX_LENGTH) {
    arr.resize(MAX_LENGTH);
}   

// Pushing to priorityQueue
void priorityQueue::push(int data) {      
    if (full()) {
        throw std::runtime_error("ERROR: Priority Queue is full");
    }                                           
    arr[currentLength] = data;
    heapifyUp(currentLength);
    ++currentLength;
}

// Popping from priorityQueue
void priorityQueue::pop() {                                                                  
    if (empty()) {
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
   swap(arr[0], arr[currentLength]);
   arr.pop_back();
    heapifyDown(0);
    --currentLength;
}

// Peeking at top of priorityQueue
int priorityQueue::top() {                                                          
    if (empty()) { 
        throw std::runtime_error("ERROR: Priority Queue is empty");
    }
    return arr[0];
}

// Check if priorityQueue is empty 
bool priorityQueue::empty() {                                                                  
    return !currentLength;
}

bool priorityQueue::full() {
    return currentLength == MAX_LENGTH;
}

// Get size of priorityQueue
int priorityQueue::size() {                                                                     
    return currentLength;
}