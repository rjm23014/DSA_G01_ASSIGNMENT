// Problem: Stack03
// Link: https://www.codechef.com/learn/course/stacks-and-queues/LSTACKS/problems/STACK03

#include <vector>
#include <string>
#include <stack>
using namespace std;

// Implement Stack using Array - Reverse String
// Problem: Reverse a given string using a stack (array implementation).

// Approach 1 - Brute Force:
// Use a dynamic vector as stack, push all chars, then pop to get reverse.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseString(string s) {
        vector<char> stack;
        for (char c : s) {
            stack.push_back(c); // Push all characters
        }
        string result;
        while (!stack.empty()) {
            result.push_back(stack.back()); // Pop from top of stack
            stack.pop_back();
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Same logic, but use std::stack for clarity and consistency.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseString(string s) {
        stack<char> st;
        for (char c : s) {
            st.push(c); // Push all characters
        }
        string result;
        while (!st.empty()) {
            result.push_back(st.top()); // Pop from top of stack
            st.pop();
        }
        return result;
    }
};
