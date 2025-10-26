// Problem: Sum Of Array2326
// Link: https://www.geeksforgeeks.org/problems/sum-of-array2326/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <vector>
#include <numeric> // for accumulate
using namespace std;

// Sum Of Array2326
// Problem: Given an integer array arr[], find the sum of its elements.

// Approach 1 - Brute Force:
// Iterate through each element and add to sum variable.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public:
    long long sumOfArray(vector<int> &arr, int n) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

// Approach 2 - Optimized:
// Use built-in accumulate function to find sum efficiently.
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
    public:
    long long sumOfArray(vector<int> &arr, int n) {
        return accumulate(arr.begin(), arr.end(), 0LL);
    }
};
