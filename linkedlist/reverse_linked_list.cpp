// Problem: Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list/description/

#include <iostream> // For NULL and nullptr definitions
using namespace std;

// Reverse Linked List
// Problem: Reverse a singly linked list given the head node

// Approach 1 - Brute Force:
// Use extra space to store all nodes' pointers, then reconstruct list backwards.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        int n = nodes.size();
        for (int i = n - 1; i > 0; --i) {
            nodes[i]->next = nodes[i - 1];
        }
        nodes[0]->next = nullptr;
        return nodes[n - 1];
    }
};

// Approach 2 - Optimized:
// Iteratively reverse pointers using three pointers: prev, curr, next.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next; // store next node
            curr->next = prev;                // reverse current node's pointer
            prev = curr;                     // move prev to current
            curr = nextTemp;                 // move curr to next
        }
        return prev; // new head of the reversed list
    }
};
