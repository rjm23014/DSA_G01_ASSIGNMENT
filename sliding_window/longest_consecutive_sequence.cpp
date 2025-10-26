// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Longest Consecutive Sequence
// Problem: Find the length of the longest consecutive elements sequence in an unsorted integer array.

// Approach 1 - Brute Force:
// Sort the array and iterate to find the longest consecutive streak.
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) or O(n) depending on sorting implementation (in-place or not)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                // skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                ++currentStreak;
            } else {
                longestStreak = max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
        return max(longestStreak, currentStreak);
    }
};

// Approach 2 - Optimized:
// Use a hash set for O(1) look-ups, and only start counting sequences from numbers that are sequence starts.
// Time Complexity: O(n) since each number is processed at most twice
// Space Complexity: O(n) for the hash set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Only try to build sequences from numbers that are sequence starts
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    ++currentNum;
                    ++currentStreak;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
