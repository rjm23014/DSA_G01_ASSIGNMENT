// Problem: Asteroid Collision
// Link: https://leetcode.com/problems/asteroid-collision/description/

#include <vector>
#include <stack>
using namespace std;

// Asteroid Collision
// Problem: Given asteroids represented by integers with size and direction,
// simulate collisions and return the state after all collisions.

// Approach 1 - Brute Force:
// Simulate collisions by checking from left to right and resolving collisions immediately.
// Time Complexity: O(n^2) in worst case due to repeated comparisons and removals.
// Space Complexity: O(n) for the output/result container.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!res.empty() && ast < 0 && res.back() > 0) {
                if (abs(ast) > res.back()) {
                    res.pop_back();
                    continue;
                } else if (abs(ast) == res.back()) {
                    res.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) res.push_back(ast);
        }
        return res;
    }
};

// Approach 2 - Optimized:
// Use a stack to maintain stable asteroids. Right movers (positive) are pushed directly.
// When encountering a left mover (negative), pop smaller right movers from the stack until resolved.
// Time Complexity: O(n) each asteroid is pushed/popped at most once.
// Space Complexity: O(n) worst case for the stack when no collisions occur.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (abs(ast) > st.top()) {
                    st.pop();
                    continue;
                } else if (abs(ast) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) st.push(ast);
        }
        vector<int> res(st.size());
        for (int i = (int)st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};
