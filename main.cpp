#include "./stack/stack.cpp"
#include <iostream>
#include <string>

int main() {
    try {
        Stack<int> stackList(10);                               // Stack of integers
        
        for (int i = 0; i < 10; i++) {                          // Pushing 0-9 to stack
            stackList.push(i);
        }

        while (!stackList.isEmpty()) {                          // Popping and printing top of stack
            std::cout << "Top: " << stackList.peek() << '\n';
            stackList.pop();
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}