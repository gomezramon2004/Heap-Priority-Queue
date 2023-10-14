#include "./queue/queue.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        Queue testList;                         // Stack of integers

        testList.push(2);
        testList.push(4);
        testList.push(6);
        testList.push(1);
        testList.push(8);

        std::cout << "Front: " << testList.top() << '\n';
        testList.pop();
        std::cout << "Front: " << testList.top() << '\n';
   
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}