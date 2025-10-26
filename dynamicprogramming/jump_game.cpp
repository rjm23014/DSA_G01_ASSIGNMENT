// Problem: Jump Game
// Link: https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

// Jump Game
// Problem: Determine if you can reach the last index from the first, given each array element as max jump length.

// Approach 1 - Brute Force:
// Recursively try every jump length from current position and check if eventually last index can be reached.
// Time Complexity: O(n^n) in worst case where n is array size (exponential)
// Space Complexity: O(n) due to recursion stack

class Solution {
public:
    bool canJumpFromPosition(int position, const vector<int>& nums) {
        if (position >= (int)nums.size() - 1) return true;
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPos = position + 1; nextPos <= furthestJump; nextPos++) {
            if (canJumpFromPosition(nextPos, nums)) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return canJumpFromPosition(0, nums);
    }
};

// Approach 2 - Optimized:
// Greedy approach tracking the maximum index reachable while iterating once.
// If at any point current index > max reachable index, return false immediately.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > maxReachable) return false; // can't reach this position
            maxReachable = max(maxReachable, i + nums[i]);
            if (maxReachable >= (int)nums.size() - 1) return true;
        }
        return true;
    }
};
