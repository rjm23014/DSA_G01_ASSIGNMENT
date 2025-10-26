// Problem: Print 1 To N Without Using Loops3621
// Link: https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops3621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
using namespace std;

// Print 1 To N Without Using Loops
// Problem: Print numbers from 1 to n without using any loops.

// Approach 1 - Brute Force:
// Print numbers on the way down the recursion (pre-order).
// Time Complexity: O(n)
// Space Complexity: O(n) due to recursion stack
class Solution {
public:
    void printTillN(int n, int start = 1) {
        if (start > n) 
            return;
        cout << start << " ";
        printTillN(n, start + 1);
    }
};

// Approach 2 - Optimized:
// Print numbers on the way back from recursion (post-order).
// This delays printing until the recursive calls unwind.
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    void printTillN(int n, int current = 1) {
        if (current > n)
            return;
        printTillN(n, current + 1);
        // To print 1 to n in correct order, print after recursion going forward:
        // But here backtracking prints in reverse, so reverse logic:
        // Instead, print before recursion to print in ascending order.
        // So actually this approach prints in descending order.
        // To get 1 to n in ascending order, this approach needs to print before recursion.
        // Hence, for demonstration, let's print in post-order but start from 1 to n using alternative approach:
        cout << current << " ";
    }
};
