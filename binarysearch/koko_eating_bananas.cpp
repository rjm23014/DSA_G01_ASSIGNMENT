// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
#include <algorithm>

using namespace std;

// Approach 1 - Brute Force:
// Try every possible eating speed from 1 up to the maximum pile size and pick
// the first speed that finishes within h hours.
// Time Complexity: O(n * maxPile)
// Space Complexity: O(1)

class BruteForceSolution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        for (int speed = 1; speed <= maxPile; ++speed) {
            if (hoursNeeded(piles, speed) <= h) {
                return speed;
            }
        }
        return maxPile;
    }

private:
    long long hoursNeeded(const vector<int>& piles, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed; // ceiling division
        }
        return hours;
    }
};

// Approach 2 - Binary Search on Answer:
// The number of hours needed decreases monotonically with speed. Binary search
// for the minimum feasible speed within [1, maxPile].
// Time Complexity: O(n log maxPile)
// Space Complexity: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(piles, mid, h)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    bool canFinish(const vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
            if (hours > h) return false;
        }
        return hours <= h;
    }
};
