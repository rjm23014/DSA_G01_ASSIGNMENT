// Problem: Implement Lower Bound
// Link: https://www.geeksforgeeks.org/implement-lower-bound/

#include <vector>
using namespace std;

// Lower Bound
// Problem: Find the smallest index in a sorted array where the element is >= target

// Approach 1 - Brute Force:
// Iterate over the array from left to right and return the first index where element >= target.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lowerBound(const vector<int>& arr, int target) {
        for (int i = 0; i < (int)arr.size(); i++) {
            if (arr[i] >= target) return i;
        }
        return arr.size();
    }
};

// Approach 2 - Optimized:
// Use binary search to find the first position where element >= target since the array is sorted.
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int lowerBound(const vector<int>& arr, int target) {
        int low = 0, high = (int)arr.size() - 1;
        int ans = arr.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
