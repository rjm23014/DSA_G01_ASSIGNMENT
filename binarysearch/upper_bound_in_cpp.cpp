// Problem: Upper Bound In Cpp
// Link: https://www.geeksforgeeks.org/upper_bound-in-cpp/

#include <vector>
using namespace std;

// Upper Bound in C++
// Problem: Given a sorted array and a value x, find the index of the first element greater than x.

// Approach 1 - Brute Force:
// Iterate through the array from the beginning and return the first index where element > x.
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
    public:
    int upperBound(const vector<int>& arr, int x) {
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] > x) return i;
        }
        return arr.size(); // No element greater than x
    }
};

// Approach 2 - Optimized:
// Use binary search to find the upper bound index efficiently in a sorted array.
// Time Complexity: O(log N)
// Space Complexity: O(1)

class Solution {
    public:
    int upperBound(const vector<int>& arr, int x) {
        int low = 0, high = (int)arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
