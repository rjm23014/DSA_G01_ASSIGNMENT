// Problem: Super Pow
// Link: https://leetcode.com/problems/super-pow/description/

#include <vector>
using namespace std;

// Super Pow
// Problem: Calculate (a^b) mod 1337, where b is a large integer represented as an array

// Approach 1 - Brute Force:
// Directly compute a^b mod 1337 by iterating through the digits and applying repeated modular exponentiation without optimization.
// Time Complexity: O(n * log 10) ~ O(n), where n = size of b (digits)
// Space Complexity: O(1)

class Solution {
public:
    static constexpr int MOD = 1337;

    int modPow(int x, int n) {
        int result = 1;
        x %= MOD;
        for (int i = 0; i < n; i++) {
            result = (result * x) % MOD;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;
        a %= MOD;
        for (int digit : b) {
            // Raise result to the power 10 and multiply by a^digit mod MOD
            result = modPow(result, 10) * modPow(a, digit) % MOD;
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use fast modular exponentiation (binary exponentiation) to compute powers more efficiently.
// Iterate through b, updating result as (result^10 * a^digit) mod 1337 efficiently.
// Time Complexity: O(n * log 10) ~ O(n)
// Space Complexity: O(1)

class Solution {
public:
    static constexpr int MOD = 1337;

    int modPow(int x, int n) {
        long long result = 1, base = x % MOD;
        while (n > 0) {
            if (n & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            n >>= 1;
        }
        return (int)result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;
        a %= MOD;
        for (int digit : b) {
            result = static_cast<long long>(modPow(result, 10)) * modPow(a, digit) % MOD;
        }
        return result;
    }
};
