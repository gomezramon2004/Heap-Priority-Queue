#include "./queue/queue.hpp"
#include <iostream>
#include <string>

// In this version of the priority queue, I'll use a vector as a container

int main() {
    try {
        priorityQueue pq(10);
        pq.push(5);
        pq.push(10);
        pq.push(15);
        pq.push(20);
        pq.push(4);

        for (int i = 0; i < 5; ++i) {
            std::cout << pq.top() << std::endl;
            pq.pop();
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}