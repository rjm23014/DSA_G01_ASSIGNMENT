// Problem: Design Circular Queue
// Link: https://leetcode.com/problems/design-circular-queue/description/

#include <vector>
using namespace std;

// Design Circular Queue
// Problem: Implement a circular queue with fixed capacity supporting enqueue, dequeue, Front, Rear, isEmpty, and isFull.

// Approach 1 - Brute Force:
// Use a vector with front and rear indices, but shift elements on dequeue to maintain order (inefficient).
// Time Complexity: O(n) per dequeue operation due to shifting
// Space Complexity: O(k) for storing k elements

class MyCircularQueue {
    vector<int> q;
    int capacity;
    int count;
public:
    MyCircularQueue(int k) : capacity(k), count(0), q(k, -1) {}

    bool enQueue(int value) {
        if (count == capacity) return false; // full
        if (count == 0) {
            q[0] = value;
            count++;
            return true;
        }
        // shift all elements right by 1 to simulate enqueue at the end (brute force)
        for (int i = count; i > 0; --i) {
            q[i] = q[i-1];
        }
        q[0] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (count == 0) return false; // empty
        // remove last element by shifting left all elements
        for (int i = 0; i < count - 1; ++i) {
            q[i] = q[i+1];
        }
        q[count - 1] = -1;
        count--;
        return true;
    }

    int Front() {
        if (count == 0) return -1;
        return q[count - 1]; // front is at the end after shifting
    }

    int Rear() {
        if (count == 0) return -1;
        return q[0]; // rear at beginning due to shift
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};


// Approach 2 - Optimized:
// Use circular indexing with two pointers (front, rear) and size tracking for O(1) enqueue and dequeue.
// Time Complexity: O(1) per operation
// Space Complexity: O(k)

class MyCircularQueue {
    vector<int> q;
    int front, rear, capacity, size;
public:
    MyCircularQueue(int k) : q(k), front(0), rear(-1), capacity(k), size(0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
