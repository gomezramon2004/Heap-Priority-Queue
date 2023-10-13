#include "./queue/queue.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        Queue testList;                         // Stack of integers
        
        for (int i = 0; i < 10; i++) {                          // Pushing 0-9 to stack
            testList.push(i);
        }

        while (!testList.empty()) {                          // Popping and printing top of stack
            std::cout << "Front: " << testList.top() << '\n';
            testList.push(100);
            testList.pop();
            testList.pop();
        }
        
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}