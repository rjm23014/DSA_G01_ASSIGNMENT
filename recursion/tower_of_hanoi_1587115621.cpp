// Problem: Tower Of Hanoi 1587115621
// Link: https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

#include <vector>
#include <string>
using namespace std;

// Tower Of Hanoi 1587115621
// Problem: Print the moves to solve Tower of Hanoi for n disks from source to target using auxiliary

// Approach 1 - Brute Force:
// Classic recursive solution that prints all moves step-by-step.
// Time Complexity: O(2^n)
// Space Complexity: O(n) for recursion stack

class Solution {
public:
    vector<string> towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod) {
        vector<string> moves;
        solve(n, from_rod, to_rod, aux_rod, moves);
        return moves;
    }

private:
    void solve(int n, int from_rod, int to_rod, int aux_rod, vector<string>& moves) {
        if (n == 0) return;
        solve(n - 1, from_rod, aux_rod, to_rod, moves);
        moves.push_back("Move disk " + to_string(n) + " from rod " + to_string(from_rod) + " to rod " + to_string(to_rod));
        solve(n - 1, aux_rod, to_rod, from_rod, moves);
    }
};

// Approach 2 - Optimized:
// There is no faster algorithm than the recursive one for listing all moves, but to reduce overhead,
// we use pass-by-reference and avoid repeated string constructions by formatting only once per move.
// Time Complexity: O(2^n)
// Space Complexity: O(n) recursion stack + O(2^n) moves storage

class Solution {
public:
    vector<string> towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod) {
        vector<string> moves;
        moves.reserve((1 << n) - 1); // reserve space to avoid reallocations
        solveOptimized(n, from_rod, to_rod, aux_rod, moves);
        return moves;
    }

private:
    void solveOptimized(int n, int from_rod, int to_rod, int aux_rod, vector<string>& moves) {
        if (n == 0) return;
        solveOptimized(n - 1, from_rod, aux_rod, to_rod, moves);
        // Pre-format the move string efficiently
        string move = "Move disk " + to_string(n) + " from rod " + to_string(from_rod) + " to rod " + to_string(to_rod);
        moves.push_back(move);
        solveOptimized(n - 1, aux_rod, to_rod, from_rod, moves);
    }
};
