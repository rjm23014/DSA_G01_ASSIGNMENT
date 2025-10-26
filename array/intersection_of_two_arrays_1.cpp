// Problem: Intersection Of Two Arrays
// Link: https://leetcode.com/problems/intersection-of-two-arrays/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Intersection Of Two Arrays
// Problem: Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must be unique.

// Approach 1 - Brute Force:
// Check every element in nums1 against nums2 to find intersections.
// Time Complexity: O(m * n), where m and n are the lengths of nums1 and nums2.
// Space Complexity: O(k), where k is the size of the intersection (for the result vector).

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < (int)nums1.size(); ++i) {
            // Check if nums1[i] is already in result to avoid duplicates
            if (find(result.begin(), result.end(), nums1[i]) != result.end())
                continue;
            for (int j = 0; j < (int)nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    break;
                }
            }
        }
        return result;
    }
};

// Approach 2 - Optimized:
// Use unordered_set for O(1) average lookup to track elements and find unique intersection.
// Time Complexity: O(m + n)
// Space Complexity: O(m + k), where m is size of nums1 and k is intersection size.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_nums1(nums1.begin(), nums1.end());
        unordered_set<int> intersection_set;
        for (int num : nums2) {
            if (set_nums1.count(num)) {
                intersection_set.insert(num); // unique elements only
            }
        }
        return vector<int>(intersection_set.begin(), intersection_set.end());
    }
};
