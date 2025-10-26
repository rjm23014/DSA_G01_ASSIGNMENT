// Problem: Count Primes
// Link: https://leetcode.com/problems/count-primes/description/

#include <vector>
#include <cmath> // for sqrt
using namespace std;

// Count Primes
// Problem: Return the number of prime numbers strictly less than n

// Approach 1 - Brute Force:
// Check for each number less than n if it is prime by testing divisors up to sqrt of the number
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(1)
class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= static_cast<int>(sqrt(num)); ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) ++count;
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Use the Sieve of Eratosthenes to mark multiples of primes and count primes below n
// Time Complexity: O(n log log n)
// Space Complexity: O(n)
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false; // 0 is not prime
        isPrime[1] = false; // 1 is not prime

        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) ++count;
        }
        return count;
    }
};
