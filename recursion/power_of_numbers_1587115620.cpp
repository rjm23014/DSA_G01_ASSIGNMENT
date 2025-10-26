// Problem: Power Of Numbers 1587115620
// Link: https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <cmath>
using namespace std;

// Power Of Numbers
// Problem: Given a number n, find n raised to the power of its own reverse.

// Approach 1 - Brute Force:
// Compute the reverse of n, then multiply n by itself reverse times.
// Time Complexity: O(m) where m is the number of digits in n to find reverse + O(reverse) for repeated multiplication.
// Space Complexity: O(1)
class Solution {
public:
    int power(int n) {
        int rev = 0, temp = n;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        int result = 1;
        for (int i = 0; i < rev; i++) {
            result *= n;
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use fast exponentiation (binary exponentiation) to compute n^rev efficiently.
// Time Complexity: O(log rev)
// Space Complexity: O(1)
class Solution {
public:
    int power(int n) {
        int rev = 0, temp = n;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }

        int result = 1;
        int base = n;
        int exponent = rev;
        while (exponent > 0) {
            if (exponent & 1) {
                result *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return result;
    }
};
