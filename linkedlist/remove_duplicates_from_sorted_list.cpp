// Problem: Remove Duplicates From Sorted List
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

#include <vector>
#include <iostream>

// [Remove Duplicates from Sorted List]
// Problem: Given the head of a sorted linked list, delete all duplicates such that each element appears only once.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach 1 - Brute Force (Not Recommended):
// This approach involves storing all node values in a vector and then iterating through the vector to remove duplicates.
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) for vector

class Solution {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> values;
        ListNode* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        
        // Sort and remove duplicates from vector
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        
        // Rebuild linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        for (int val : values) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        
        return dummy.next;
    }
};

// Approach 2 - Optimized:
// This solution iterates through the linked list, removing duplicates as it goes.
// Time Complexity: O(n)
// Space Complexity: O(1)

class SolutionOptimized {
    public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            while (curr->next && curr->val == curr->next->val) {
                curr->next = curr->next->next; // Skip duplicates
            }
            curr = curr->next; // Move to next node
        }
        return head;
    }
};
