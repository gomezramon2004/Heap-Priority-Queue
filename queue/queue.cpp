#include "queue.hpp"
#include <algorithm> 

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

        // Perform "sift-up" to maintain the heap property.
        Node* current = rear;
        while (current != front) {
            Node* parent = nullptr;
            Node* tmp = front;

            // Find the parent of the current node.
            while (tmp) {
                if (tmp->next == current) {
                    parent = tmp;
                    break;
                }
                tmp = tmp->next;
            }

            if (parent && parent->data > current->data) {
                std::swap(parent->data, current->data);
                current = parent;
            } else {
                break;  // The heap property is maintained.
            }
        }
    }
    ++length;
}

// Popping from Queue
void Queue::pop() {
    if (empty()) {
        throw std::runtime_error("ERROR: Queue is empty");
    }

    // If there's only one element in the queue, remove it.
    if (length == 1) {
        delete front;
        front = rear = nullptr;
        length = 0;
        return;
    }

    // Swap the first and last nodes.
    std::swap(front->data, rear->data);

    // Remove the last node.
    Node* current = front;
    while (current->next != rear) {
        current = current->next;
    }

    delete rear;
    rear = current;
    rear->next = nullptr;

    // Perform "sift-down" to maintain the heap property.
    current = front;
    while (current) {
        Node* leftChild = current->next;
        Node* rightChild = leftChild ? leftChild->next : nullptr;
        Node* smallest = current;

        if (leftChild && leftChild->data < smallest->data) {
            smallest = leftChild;
        }

        if (rightChild && rightChild->data < smallest->data) {
            smallest = rightChild;
        }

        if (smallest != current) {
            std::swap(current->data, smallest->data);
            current = smallest;
        } else {
            break;  // The heap property is maintained.
        }
    }

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
