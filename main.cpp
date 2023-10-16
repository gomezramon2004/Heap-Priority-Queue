#include "./queue/queue.hpp"
#include <iostream>
#include <string>

// In this version of the priority queue, I'll use a vector as a container

int main() {
    try {
        // Heap Tree Basic Structure - For the testcases

        priorityQueue pq(10);

        // Push Testcases

        pq.push(5);     // First Case
        pq.push(10);    // Second Case
        pq.push(15);
        pq.push(20);
        pq.push(4);     // Third Case
        pq.push(25);    // Fourth Case

        // Pop, Top, Empty and Size Testcases

        while (!pq.empty()) {                            // A case for each loop (six in total)
            std::cout << "Top: "<< pq.top() << std::endl;
            std::cout << "Size: "<< pq.size() << std::endl;
            pq.pop();
        }

    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}