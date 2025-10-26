// Problem: Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i/description/

#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

// Next Greater Element I
// Problem: For each element in nums1, find the next greater element in nums2
// nums1 is a subset of nums2, and nums2 has no duplicates.

// Approach 1 - Brute Force:
// For each element in nums1, scan nums2 from the element's position to the right to find the first greater element.
// Time Complexity: O(m * n), where m = nums1.size(), n = nums2.size()
// Space Complexity: O(1)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int x : nums1) {
            int next_greater = -1;
            bool found = false;
            for (int i = 0; i < (int)nums2.size(); ++i) {
                if (nums2[i] == x) {
                    found = true;
                    continue;
                }
                if (found && nums2[i] > x) {
                    next_greater = nums2[i];
                    break;
                }
            }
            res.push_back(next_greater);
        }
        return res;
    }
};

// Approach 2 - Optimized:
// Use a monotonic stack to preprocess nums2 for next greater elements.
// Build a map from element to its next greater element in nums2 in O(n).
// Then map each nums1 element to answer using this map.
// Time Complexity: O(n + m), n = nums2.size(), m = nums1.size()
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater_map;
        stack<int> stk;
        for (int i = (int)nums2.size() - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }
            next_greater_map[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int> res;
        for (int x : nums1) {
            res.push_back(next_greater_map[x]);
        }
        return res;
    }
};
