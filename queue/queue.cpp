#include "queue.hpp"

// Constructor of Node
Node::Node(int data) : data(data), next(nullptr) {}        


// Implementation of Queue Methods

// Constructor
Queue::Queue() : length(0), front(nullptr), rear(nullptr) {}                                

// Pushing to Queue
void Queue::push(int data) {                                                 
    Node* newNode = new Node(data);
    if (empty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    ++length;
}

// Popping from Queue
void Queue::pop() {                                                                  
    if (empty()) {
        throw std::runtime_error("ERROR: Queue is empty");
    }
    Node* temp = front;
    front = front->next;
    delete temp;
    --length;
}

// Peeking at top of Queue
int Queue::top() {                                                          
    if (empty()) { 
        throw std::runtime_error("ERROR: Queue is empty"); 
    }
    return front->data;
}

// Check if Queue is empty 
bool Queue::empty() {                                                                  
    return !front;
}

// Get size of Queue
int Queue::size() {                                                                     
    return length;
}

 // Destructor 
Queue::~Queue() {                                                          
    while (!empty()) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    length = 0;
}
