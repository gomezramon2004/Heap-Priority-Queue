#include "./stack/stack.cpp"
#include <iostream>
#include <string>

int main() {
    try {
        Stack<int> stackList(10);
        
        for (int i = 0; i < 10; i++) {
            stackList.push(i);
        }

        while (!stackList.isEmpty()) {
            std::cout << "Top: " << stackList.getTop() << '\n';
            stackList.pop();
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}