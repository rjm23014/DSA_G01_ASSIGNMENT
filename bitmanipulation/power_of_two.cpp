// Problem: Power Of Two
// Link: https://leetcode.com/problems/power-of-two/description/

#include <vector>
#include <cmath>
using namespace std;

// Power Of Two
// Problem: Determine if a given integer is a power of two.

// Approach 1 - Brute Force:
// [Brief explanation]
// This approach checks if a number is a power of two by continuously dividing it by two until it becomes less than or equal to zero or it is no longer divisible evenly by two.
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
    public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Negative numbers and zero are not powers of two
        while (n % 2 == 0) {
            n /= 2; // Keep dividing by two if it is divisible
        }
        return n == 1; // If n becomes 1, it is a power of two
    }
};

// Approach 2 - Optimized:
// [Brief explanation]
// This approach uses bit manipulation to check if only one bit is set in the binary representation of the number.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
    public:
    bool isPowerOfTwo(int n) {
        // Check if n is positive and has only one bit set
        return n > 0 && (n & (n - 1)) == 0;
    }
};
