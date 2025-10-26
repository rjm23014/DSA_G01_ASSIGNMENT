// Problem: Smaller On Left20360700
// Link: https://www.geeksforgeeks.org/problems/smaller-on-left20360700/1

#include <vector>
#include <stack>
using namespace std;

// Smaller On Left
// Problem: For each element in the array, find the nearest smaller element on its left; if none exists, return -1.

// Approach 1 - Brute Force:
// For each element, scan leftwards to find the nearest smaller element by checking all previous elements.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> smallerElement(int n, vector<int> &arr) {
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int smaller = -1;
            for(int j = i - 1; j >= 0; j--) {
                if(arr[j] < arr[i]) {
                    smaller = arr[j];
                    break;
                }
            }
            result[i] = smaller;
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use a stack to keep track of candidates for the nearest smaller element on the left.
// For each element, pop elements from stack while they are >= current element, then top of stack (if exists) is answer.
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> smallerElement(int n, vector<int> &arr) {
        vector<int> result;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if(st.empty())
                result.push_back(-1);
            else
                result.push_back(st.top());
            st.push(arr[i]);
        }
        return result;
    }
};
