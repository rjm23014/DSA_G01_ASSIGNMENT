// Problem: Count Nodes Of Linked List
// Link: https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
// No extra includes needed for singly linked list traversal
using namespace std;

// Count Nodes Of Linked List
// Problem: Given the head of a singly linked list, count the number of nodes in it.

// Approach 1 - Brute Force:
// Iterate through each node in the linked list, incrementing a counter until reaching null.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    // Function to count nodes of linked list
    int getCount(struct Node* head) {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Approach 2 - Optimized:
// The problem inherently requires traversal of all nodes to count them,
// so the optimized approach is essentially the same as brute force.
// Recursive counting can be done but it adds call stack overhead.
// Time Complexity: O(n)
// Space Complexity: O(n) for recursion stack, O(1) for iterative

class SolutionRecursive {
public:
    int getCount(struct Node* head) {
        if (head == nullptr) return 0;
        return 1 + getCount(head->next);
    }
};
