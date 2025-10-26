// Problem: Middle Of The Linked List
// Link: https://leetcode.com/problems/middle-of-the-linked-list/description/

#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
using namespace std;

// Middle Of The Linked List
// Problem: Return the middle node of a singly linked list. If two middle nodes exist, return the second one.

// Approach 1 - Brute Force:
// Traverse the list to count the total nodes, then traverse again to the middle.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current) {  // count nodes
            count++;
            current = current->next;
        }
        int mid = count / 2;  // middle index (second middle if even)
        current = head;
        for (int i = 0; i < mid; i++) {  // move to middle node
            current = current->next;
        }
        return current;
    }
};

// Approach 2 - Optimized:
// Use two pointers, slow moves one step, fast moves two steps. When fast reaches end, slow is middle.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
