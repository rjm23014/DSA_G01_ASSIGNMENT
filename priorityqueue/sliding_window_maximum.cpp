// Problem: Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/

#include <vector>
#include <deque>
using namespace std;

// Sliding Window Maximum
// Problem: Return the max of each sliding window of size k as you move right in nums.

// Approach 1 - Brute Force:
// Check every possible window, find max in each.
// Time Complexity: O((n - k + 1)*k) = O(n*k)
// Space Complexity: O(1) (if output not counted), else O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i <= nums.size() - k; ++i) {
            int maxi = nums[i];
            for (int j = 1; j < k; ++j)
                if (nums[i+j] > maxi) maxi = nums[i+j];
            res.push_back(maxi);
        }
        return res;
    }
};

// Approach 2 - Optimized (Monotonic Deque):
// Use deque to store indices of promising candidates (always in decreasing order).
// Time Complexity: O(n) (each element added/removed at most twice)
// Space Complexity: O(k) (deque size <= k), output O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements not in window from front
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            // Remove elements <= nums[i] from back (monotonic)
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            // Start adding results once window is established
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
