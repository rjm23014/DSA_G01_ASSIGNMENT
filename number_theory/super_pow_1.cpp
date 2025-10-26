// Problem: Super Pow
// Link: https://leetcode.com/problems/super-pow/description/

#include <vector>
using namespace std;

// Super Pow
// Problem: Calculate a^b mod 1337 where b is an extremely large integer given as an array of digits.

// Approach 1 - Brute Force:
// Compute a^b directly by iterating through the digits of b and repeatedly multiplying with modular exponentiation without optimization.
// Time Complexity: O(n * 1337), where n is the length of b, due to repeated naive exponentiation.
// Space Complexity: O(1)

class Solution {
public:
    static constexpr int kMod = 1337;

    int modPow(int base, int exp) {
        int result = 1;
        base %= kMod;
        for (int i = 0; i < exp; ++i) {
            result = (result * base) % kMod;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        a %= kMod;
        int result = 1;
        for (int digit : b) {
            // Raise current result to the power 10, then multiply by a^digit (mod kMod)
            result = modPow(result, 10) * modPow(a, digit) % kMod;
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use fast modular exponentiation (binary exponentiation) and handle large exponent b digit by digit,
// applying the exponentiation rule: a^b = (a^{10})^{b_rest} * a^{last_digit} mod kMod.
// Time Complexity: O(n * log 10) = O(n), since each modPow is O(log exponent) and exponent is at most 10.
// Space Complexity: O(1)

class Solution {
public:
    static constexpr int kMod = 1337;

    int modPow(int base, int exp) {
        long long result = 1, cur = base % kMod;
        while (exp > 0) {
            if (exp & 1) result = (result * cur) % kMod;
            cur = (cur * cur) % kMod;
            exp >>= 1;
        }
        return (int)result;
    }

    int superPow(int a, vector<int>& b) {
        a %= kMod;
        int result = 1;
        for (int digit : b) {
            result = (long long)modPow(result, 10) * modPow(a, digit) % kMod;
        }
        return result;
    }
};
