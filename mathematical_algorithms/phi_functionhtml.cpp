// Problem: Phi Function.Html
// Link: https://cp-algorithms.com/algebra/phi-function.html

#include <vector>
#include <numeric> // for gcd

using namespace std;

// Brute Force Solution
class BruteForceSolution {
public:
    int phi(int n) {
        int count = 0; // Count of numbers relatively prime to n
        for (int i = 1; i <= n; i++) {
            if (gcd(i, n) == 1) {
                count++;
            }
        }
        return count;
    }
};

// Time Complexity: O(n log n)
// Space Complexity: O(1)
