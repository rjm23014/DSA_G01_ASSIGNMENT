// Problem: Rotate List
// Link: https://leetcode.com/problems/rotate-list/description/

#include <vector>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;

// Rotate List
// Problem: Rotate a linked list to the right by k places.

// Approach 1 - Brute Force:
// This approach is not typical for this problem. Normally, we wouldn't use a brute force method for this problem, as it involves directly manipulating the linked list.
// Time Complexity: O(n * k)
// Space Complexity: O(1)

class SolutionBruteForce {
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Simulate rotation k times
        for (int i = 0; i < k; i++) {
            ListNode* current = head;
            ListNode* prev = NULL;
            // Find the last node
            while (current->next) {
                prev = current;
                current = current->next;
            }
            // Rotate
            current->next = head;
            head = current;
            prev->next = NULL;
        }
        return head;
    }
};

// Approach 2 - Optimized:
// This approach counts the number of nodes, calculates the effective rotation, and uses two pointers to perform the rotation efficiently.
// Time Complexity: O(n)
// Space Complexity: O(1)

class SolutionOptimized {
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // Count the number of nodes
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        
        // Connect the tail to the head to form a ring
        tail->next = head;
        
        // Calculate effective rotation
        k %= n;
        if (k == 0) return head; // No rotation needed
        
        // Move the pointer to the node before the new tail
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++) {
            newTail = newTail->next;
        }
        
        // Perform the rotation
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
