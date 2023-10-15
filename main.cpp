#include "./queue/queue.hpp"
#include <iostream>
#include <string>

// In this version of the priority queue, I'll use nodes as a container for the dat

int main() {
    try {
        priorityQueue pq;
        pq.push(5);
        std::cout << pq.top() << std::endl;
        pq.push(10);
        std::cout << pq.top() << std::endl;
        pq.push(15);
        std::cout << pq.top() << std::endl;
        pq.push(20);
        std::cout << pq.top() << std::endl;
        pq.push(4);
        std::cout << pq.top() << std::endl;

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}