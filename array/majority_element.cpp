// Problem: Majority Element
// Link: https://leetcode.com/problems/majority-element/description/

#include <vector>
#include <unordered_map>
using namespace std;

// Majority Element
// Problem: Return the element that appears more than n/2 times in the array

// Approach 1 - Brute Force:
// Count frequencies using a hashmap and return the element with frequency > n/2
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n / 2) {
                return num;
            }
        }
        // Majority element always exists, so no need for a fallback
        return -1;
    }
};

// Approach 2 - Optimized:
// Boyer-Moore Voting Algorithm to find majority element in one pass with O(1) space
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        // candidate is the majority element as guaranteed by problem constraints
        return candidate;
    }
};
