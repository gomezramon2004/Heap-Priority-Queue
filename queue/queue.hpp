#pragma once
#include <vector>

class priorityQueue {
    private:
        int currentLength;
        int MAX_LENGTH;
        std::vector<int> arr;
        void swap(int &a, int &b);
        void heapifyUp(int index);
        void heapifyDown(int index);
    public:
        priorityQueue(int MAX_LENGTH);
        void push(int data);
        void pop();
        int top(); 
        bool empty();
        bool full();
        int size();
};