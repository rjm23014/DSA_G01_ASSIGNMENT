// Problem: Can Place Flowers
// Link: https://leetcode.com/problems/can-place-flowers/description/

#include <vector>
using namespace std;

// Can Place Flowers
// Problem: Given a flowerbed (0: empty, 1: flower) and n, return true if n flowers can be planted without adjacent flowers.

// Approach 1 - Brute Force:
// Iterate through each plot; for each empty plot, check adjacent plots. Plant if possible, count planted flowers.
// Time Complexity: O(M), M = flowerbed size
// Space Complexity: O(1)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int count = 0;
        for (size_t i = 0; i < flowerbed.size(); ++i) {
            bool prev_ok = (i == 0 || flowerbed[i-1] == 0);
            bool next_ok = (i == flowerbed.size()-1 || flowerbed[i+1] == 0);
            if (flowerbed[i] == 0 && prev_ok && next_ok) {
                flowerbed[i] = 1;
                ++count;
                if (count >= n) return true;
            }
        }
        return false;
    }
};

// Approach 2 - Optimized (Early Termination & Boundary Handling):
// Pad flowerbed with 0s to handle boundaries uniformly. Skip plots that can't be planted. Early terminate if target reached.
// Time Complexity: O(M)
// Space Complexity: O(1)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (size_t i = 1; i < flowerbed.size() - 1 && n > 0; ++i) {
            if (flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                --n;
            }
        }
        flowerbed.pop_back();
        flowerbed.erase(flowerbed.begin());
        return n == 0;
    }
};
