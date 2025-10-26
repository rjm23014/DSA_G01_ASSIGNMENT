// Problem: Lemonade Change
// Link: https://leetcode.com/problems/lemonade-change/description/

#include <vector>
#include <iostream>
using namespace std;

// Lemonade Change
// Problem: Determine if correct change can be provided to all customers paying $5, $10, or $20 bills without initial change.

// Approach 1 - Brute Force:
// Briefly, this approach involves checking every possible combination of bills to see if change can be made. However, due to its inefficiency, a more practical brute force for this problem is not feasible. Instead, we'll directly implement an optimized solution as the brute force approach is not practical for this scenario.

// Approach 2 - Optimized (Greedy Algorithm):
// Briefly, use a greedy algorithm to track the number of $5 and $10 bills available to make change. For $10, give one $5. For $20, prefer one $10 and one $5, or three $5s as an alternative.
// Time Complexity: O(n), where n is the number of customers.
// Space Complexity: O(1), as only a constant amount of space is used.

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveDollarBills = 0; // Track $5 bills
        int tenDollarBills = 0; // Track $10 bills

        for (int bill : bills) {
            switch (bill) {
                case 5:
                    fiveDollarBills++; // Customer pays with $5, no change needed
                    break;
                case 10:
                    if (fiveDollarBills == 0) return false; // Insufficient $5 bills for change
                    fiveDollarBills--; // Give $5 as change
                    tenDollarBills++; // Collect $10
                    break;
                case 20:
                    if (tenDollarBills > 0 && fiveDollarBills > 0) {
                        tenDollarBills--; // Prefer giving $10 and $5
                        fiveDollarBills--;
                    } else if (fiveDollarBills >= 3) {
                        fiveDollarBills -= 3; // Give three $5s as change
                    } else {
                        return false; // Insufficient bills for change
                    }
                    break;
            }
            if (fiveDollarBills < 0) return false; // If negative $5 bills
        }
        return true; // Successful transaction for all customers
    }
};
