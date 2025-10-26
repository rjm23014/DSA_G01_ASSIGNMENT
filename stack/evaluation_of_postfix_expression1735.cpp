// Problem: Evaluation Of Postfix Expression1735
// Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <stack>
#include <string>
using namespace std;

// Evaluation Of Postfix Expression

// Problem: Given an postfix expression, evaluate and return its result as an integer.

// Approach 1 - Brute Force:
// Iterate through expression, pushing all operands onto stack; when operator encountered, pop top two, compute result, push back.
// Handles only single-digit operands.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int evaluatePostfix(string S) {
        stack<int> s;
        for (char c : S) {
            if (isdigit(c)) {
                s.push(c - '0');
            } else {
                int op2 = s.top(); s.pop(); // Note: op2 is popped before op1
                int op1 = s.top(); s.pop();
                switch (c) {
                    case '+': s.push(op1 + op2); break;
                    case '-': s.push(op1 - op2); break;
                    case '*': s.push(op1 * op2); break;
                    case '/': s.push(op1 / op2); break;
                }
            }
        }
        return s.top();
    }
};

// Approach 2 - Optimized:
// Tokenize expression by splitting on spaces, then process each token.
// Handles multi-digit operands and spaces as delimiters.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int evaluatePostfix(string S) {
        stack<int> s;
        int i = 0, n = S.size();
        while (i < n) {
            if (S[i] == ' ') {
                i++;
                continue;
            }
            if (isdigit(S[i])) {
                int num = 0;
                while (i < n && isdigit(S[i])) {
                    num = num * 10 + (S[i] - '0');
                    i++;
                }
                s.push(num);
            } else {
                int op2 = s.top(); s.pop();
                int op1 = s.top(); s.pop();
                switch (S[i]) {
                    case '+': s.push(op1 + op2); break;
                    case '-': s.push(op1 - op2); break;
                    case '*': s.push(op1 * op2); break;
                    case '/': s.push(op1 / op2); break;
                }
                i++;
            }
        }
        return s.top();
    }
};
