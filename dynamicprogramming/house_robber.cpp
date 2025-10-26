// Problem: House Robber
// Link: https://leetcode.com/problems/house-robber/

#include <vector>
#include <unordered_map>
using namespace std;

// House Robber
// Problem: Find the maximum amount that can be robbed from non-adjacent houses.

// Approach 1 - Brute Force with Memoization:
// Brief explanation: This approach checks all possible combinations of robbing houses while avoiding adjacent ones. It uses memoization to store computed results for efficiency.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> memo;
        
        // Recursive helper function with memoization
        function<int(int)> dfs = [&](int i) {
            if (i >= n) return 0; // Base case
            if (memo.count(i)) return memo[i]; // If already computed
            
            // Rob current or skip it
            int robCurrent = nums[i] + dfs(i + 2);
            int skipCurrent = dfs(i + 1);
            
            memo[i] = max(robCurrent, skipCurrent);
            return memo[i];
        };
        
        return dfs(0); // Start from the first house
    }
};

// Approach 2 - Optimized Dynamic Programming:
// Brief explanation: This approach uses dynamic programming to store the maximum amount that can be robbed up to each house, avoiding adjacent houses.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // No houses
        if (n == 1) return nums[0]; // Only one house
        
        int secondLast = 0, last = nums[0]; // Initialize previous two values
        
        for (int i = 1; i < n; i++) {
            // Compute current value using previous two values
            int current = max(nums[i] + secondLast, last);
            secondLast = last; // Update second last
            last = current; // Update last
        }
        
        return last; // Return the maximum amount
    }
};
