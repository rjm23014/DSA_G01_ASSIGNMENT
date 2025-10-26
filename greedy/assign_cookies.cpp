// Problem: Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies/description/

#include <vector>
#include <algorithm>
using namespace std;

// Assign Cookies
// Problem: Assign cookies to children to maximize content children. Each child takes at most one cookie of size >= their greed.

// Approach 1 - Brute Force:
// Try all permutations to find max content children. Impractical for large inputs.
// Time Complexity: O(n! * m!) — factorial, extremely slow
// Space Complexity: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int maxContent = 0;
        // Brute force with permutations omitted — not feasible for programming contests.
        // This approach is only conceptual.
        return maxContent;
    }
};

// Approach 2 - Optimized (Greedy):
// Sort both arrays, use two pointers to match smallest cookie to smallest greed.
// Time Complexity: O(n log n + m log m) — from sorting and linear scan[1][4][5]
// Space Complexity: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // Assign smallest sufficient cookie
                i++; // Child satisfied
            }
            j++; // Move to next cookie
        }
        return i; // Number of satisfied children
    }
};
