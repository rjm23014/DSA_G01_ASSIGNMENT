// Problem: Count Digits5716
// Link: https://www.geeksforgeeks.org/problems/count-digits5716/0

#include <iostream>
using namespace std;

// Count Digits
// Problem: Given a number N, count how many digits of N evenly divide N.

// Approach 1 - Brute Force:
// Convert number to string or consider digits iteratively, check divisibility for each digit.
// Time Complexity: O(log N) because digits are processed once.
// Space Complexity: O(1)

class Solution {
public:
    int countDigits(int N) {
        int count = 0;
        int original = N;
        while (N) {
            int d = N % 10;
            if (d != 0 && original % d == 0) {
                ++count;
            }
            N /= 10;
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Same as brute force because the problem requires checking each digit; no known asymptotic improvement.
// Using string conversion, which is cleaner but still O(log N) time and O(log N) space for string.
// Time Complexity: O(log N)
// Space Complexity: O(log N) for string representation

class Solution {
public:
    int countDigits(int N) {
        int count = 0;
        string s = to_string(N);
        for (char c : s) {
            int d = c - '0';
            if (d != 0 && N % d == 0) {
                ++count;
            }
        }
        return count;
    }
};
