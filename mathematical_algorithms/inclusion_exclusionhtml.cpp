// Problem: Inclusion Exclusion.Html
// Link: https://cp-algorithms.com/combinatorics/inclusion-exclusion.html

#include <vector>
#include <numeric>  // for gcd
#include <cstddef>  // for size_t
using namespace std;

// Inclusion-Exclusion Principle
// Problem: Count numbers ≤ N divisible by any of given primes (or sets of divisors)

// Approach 1 - Brute Force:
// Iterate through 1 to N, check divisibility for each of the primes.
// Time Complexity: O(N * k), where k = number of primes
// Space Complexity: O(1)

class Solution {
public:
    int countDivisibleBruteForce(int N, const vector<int>& primes) {
        int count = 0;
        for (int i = 1; i <= N; ++i) {
            for (auto p : primes) {
                if (i % p == 0) {
                    ++count;
                    break;  // count once per number if divisible by any prime
                }
            }
        }
        return count;
    }
};

// Approach 2 - Optimized:
// Use Inclusion-Exclusion principle to count multiples precisely.
// Iterate over all non-empty subsets of primes, use lcm to find multiples and add/subtract accordingly.
// Time Complexity: O(2^k * k) due to subset iterations and lcm computations
// Space Complexity: O(k)

class Solution {
public:
    // Compute lcm of two numbers
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    int countDivisibleInclusionExclusion(int N, const vector<int>& primes) {
        size_t k = primes.size();
        int result = 0;
        
        // Iterate over all non-empty subsets of primes
        // Use bitmask from 1 to 2^k - 1
        for (int mask = 1; mask < (1 << k); ++mask) {
            long long mul = 1;
            int bitsCount = 0;
            bool overflow = false;
            
            for (int i = 0; i < (int)k; ++i) {
                if (mask & (1 << i)) {
                    ++bitsCount;
                    // Compute lcm carefully to avoid overflow
                    mul = lcm(mul, primes[i]);
                    if (mul > N) {
                        overflow = true;
                        break;
                    }
                }
            }
            if (!overflow) {
                int curCount = N / (int)mul;
                if (bitsCount % 2 == 1) {  // odd size subset => add
                    result += curCount;
                } else {                   // even size subset => subtract
                    result -= curCount;
                }
            } 
        }
        return result;
    }
};
