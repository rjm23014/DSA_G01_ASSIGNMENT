// Problem: Find All Repeating Elements In An Array
// Link: https://takeuforward.org/data-structure/find-all-repeating-elements-in-an-array/

#include <vector>
#include <unordered_map>
#include <unordered_set>

// Find All Repeating Elements In An Array
// Problem: Given an array, find all elements that are repeated at least once.

// Approach 1 - Brute Force:
// For each element, check if it exists elsewhere in the array.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> findRepeatingElements(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bool is_repeated = false;
            // Check for duplicate in previous elements
            for (int j = 0; j < i; ++j) {
                if (nums[j] == nums[i]) {
                    is_repeated = true;
                    break;
                }
            }
            // If already marked as repeated, skip to avoid duplicates in result
            if (is_repeated) continue;
            // Check for duplicate in upcoming elements
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == nums[i]) {
                    result.push_back(nums[i]);
                    is_repeated = true;
                    break;
                }
            }
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Count elements in a hash map, then collect those with count > 1.
// Time Complexity: O(n)
// Space Complexity: O(n) [3]

class Solution {
public:
    vector<int> findRepeatingElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_set<int> added; // to avoid duplicates in result
        vector<int> result;
        for (int num : nums) freq[num]++;
        for (int num : nums)
            if (freq[num] > 1 && added.insert(num).second)
                result.push_back(num);
        return result;
    }
};
