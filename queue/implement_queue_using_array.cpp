// Problem: Implement Queue Using Array
// Link: https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

#include <iostream>
#include <vector>

// Implement Queue Using Array
// Problem: Implement a queue using an array, supporting enqueue and dequeue operations.

// Approach 1 - Brute Force (Not Typical for Queue):
// Explanation: This approach is not typical for queue implementation since it does not handle the queue's circular nature efficiently. However, it demonstrates simple shift operations for enqueue and dequeue.
// Time Complexity: O(n) for enqueue and dequeue due to shifting elements.
// Space Complexity: O(k), where k is the size of the queue.

class MyQueue1 {
public:
    std::vector<int> data;
    int k;

    MyQueue1(int k) : k(k) {}

    void push(int x) {
        // Check if queue is full
        if (data.size() == k) return;
        
        // Shift all elements to the right for insertion at the beginning
        data.insert(data.begin(), x);
    }

    void pop() {
        // Check if queue is empty
        if (data.empty()) return;
        data.erase(data.begin()); // Remove the first element
    }

    int peek() {
        return !data.empty() ? data.front() : -1; // Return -1 if empty
    }

    bool empty() {
        return data.empty();
    }
};

// Approach 2 - Optimized (Circular Array):
// Explanation: This approach uses a circular array to efficiently handle enqueue and dequeue operations. It maintains front and rear pointers to track the first and last elements in the queue.
// Time Complexity: O(1) for enqueue and dequeue.
// Space Complexity: O(k), where k is the size of the queue.

class MyQueue2 {
public:
    std::vector<int> data;
    int front, rear, k;

    MyQueue2(int k) : front(0), rear(-1), k(k), data(k) {}

    void push(int x) {
        // Check if queue is full
        if (isFull()) return;

        // Move rear pointer and insert at the new position
        data[++rear % k] = x;
    }

    void pop() {
        // Check if queue is empty
        if (isEmpty()) return;

        // Move front pointer
        front = (front + 1) % k;
    }

    int peek() {
        return !isEmpty() ? data[front] : -1; // Return -1 if empty
    }

    bool empty() {
        return isEmpty();
    }

    bool isEmpty() {
        return front == (rear + 1) % k || (front == 0 && rear == -1);
    }

    bool isFull() {
        return front == (rear + 1) % k;
    }
};
