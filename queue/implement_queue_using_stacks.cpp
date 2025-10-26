// Problem: Implement Queue Using Stacks
// Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <vector>
#include <stack>
using namespace std;

// Implement Queue Using Stacks
// Problem: Implement a queue using two stacks.

// Approach 1 - Brute Force (Costly Enqueue):
// Brief Explanation: Enqueue operation involves shifting elements to maintain queue order.
// Time Complexity: O(n) for enqueue, O(1) for dequeue
// Space Complexity: O(n)

class SolutionBrute {
public:
    stack<int> stk1, stk2;
    
    void push(int x) {
        // Pop from stk1 and push to stk2 to maintain order
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        // Push new element to stk1 (now empty)
        stk1.push(x);
        // Restore original order by popping from stk2 and pushing to stk1
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    int pop() {
        // Just pop from stk1
        int res = stk1.top();
        stk1.pop();
        return res;
    }
    
    int peek() {
        // Front element is at the top of stk1
        return stk1.top();
    }
    
    bool empty() {
        return stk1.empty();
    }
};

// Approach 2 - Optimized (Costly Dequeue):
// Brief Explanation: Use one stack for enqueue and another for dequeue. Dequeue involves moving elements from enqueue stack to dequeue stack when necessary.
// Time Complexity: O(1) for enqueue, O(n) for first dequeue
// Space Complexity: O(n)

class SolutionOptimized {
public:
    stack<int> stk1, stk2;
    
    void push(int x) {
        // Simply push to stk1
        stk1.push(x);
    }
    
    int pop() {
        // Move elements from stk1 to stk2 if stk2 is empty
        moveStk1ToStk2();
        // Pop from stk2
        int res = stk2.top();
        stk2.pop();
        return res;
    }
    
    int peek() {
        // Move elements if necessary
        moveStk1ToStk2();
        // Return top of stk2
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
    
    void moveStk1ToStk2() {
        // Move elements from stk1 to stk2 if stk2 is empty
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
    }
};
