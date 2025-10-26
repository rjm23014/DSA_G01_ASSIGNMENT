// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/description/

#include <stack>
#include <algorithm>
using namespace std;

// Min Stack
// Problem: Design a stack supporting push, pop, top, and retrieving the minimum element in O(1)

// Approach 1 - Brute Force:
// Store all elements in a stack. To get minimum, scan through all elements each time.
// Time Complexity: push/pop/top - O(1), getMin - O(n)
// Space Complexity: O(n)

class MinStack {
    stack<int> st;
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
    }

    void pop() {
        if (!st.empty()) st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        int minVal = INT_MAX;
        stack<int> temp = st;
        while (!temp.empty()) {
            minVal = min(minVal, temp.top());
            temp.pop();
        }
        return minVal;
    }
};

// Approach 2 - Optimized:
// Use two stacks: one for all values, one for tracking minimums at each insertion.
// Time Complexity: push/pop/top/getMin - O(1)
// Space Complexity: O(n)

class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top());
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
