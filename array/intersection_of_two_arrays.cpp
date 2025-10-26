// Problem: Intersection Of Two Arrays
// Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <vector>
#include <unordered_set>
#include <cstring>
using namespace std;

// Intersection Of Two Arrays
// Problem: Return unique elements present in both nums1 and nums2

// Approach 1 - Brute Force:
// Use a fixed-size boolean array (assuming input values limited) to track presence from nums1.
// Then iterate nums2 to check and collect unique intersections.
// Time Complexity: O(m + n) where m and n are sizes of nums1 and nums2
// Space Complexity: O(1) due to fixed size auxiliary array (assuming constrained input range)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool seen[1001];                // Assumes elements in [0, 1000]
        memset(seen, false, sizeof(seen));
        for (int num : nums1) {
            seen[num] = true;
        }
        vector<int> result;
        for (int num : nums2) {
            if (seen[num]) {            // If num in nums1 and not yet added
                result.push_back(num);
                seen[num] = false;      // Avoid duplicates in result
            }
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use unordered_set to store unique elements of nums1 for O(1) lookups,
// then check nums2 elements in the set, add and remove to avoid duplicates.
// Time Complexity: O(m + n)
// Space Complexity: O(min(m, n)) for the hash set

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_nums1(nums1.begin(), nums1.end());
        vector<int> result;
        for (int num : nums2) {
            if (set_nums1.erase(num)) { // erase returns 1 if an element was erased
                result.push_back(num);
            }
        }
        return result;
    }
};
