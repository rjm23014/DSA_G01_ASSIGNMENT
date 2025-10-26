// Problem: Zero Sum Subarrays1825
// Link: https://www.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

#include <vector>
#include <unordered_map>
using namespace std;

// Zero Sum Subarrays
// Problem: Count the number of subarrays in a given array that sum to zero.

// Approach 1 - Brute Force:
// Check every possible subarray and count those with sum zero.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];
                if (sum == 0) ans++;
            }
        }
        return ans;
    }
};

// Approach 2 - Optimized:
// Use prefix sum and hash map to track sum frequencies.
// Whenever a sum is repeated, it means a subarray sums to zero between those indices.
// Sum zero at any index counts as an additional subarray.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        unordered_map<long long, int> prefix; // sum -> count
        prefix[0] = 1; // empty subarray
        long long ans = 0, sum = 0;
        for (auto x : arr) {
            sum += x;
            ans += prefix[sum]; // add previous occurrences
            prefix[sum]++;      // update count for current sum
        }
        return ans;
    }
};
