// Problem: Search An Element In A Linked List Iterative And Recursive Data Structures Algorithm 0C3Fad1Cd1D6
// Link: https://medium.com/@itsanuragjoshi/search-an-element-in-a-linked-list-iterative-and-recursive-data-structures-algorithm-0c3fad1cd1d6

#include <iostream>
using namespace std;

// Search An Element In A Linked List
// Problem: Determine if a given key exists in a singly linked list.

// Definition for singly-linked list node.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Approach 1 - Brute Force:
// Iteratively traverse the linked list and compare each node's data with the target key.
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(1) as no extra space is used

class Solution {
public:
    bool search(Node* head, int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key)
                return true;
            current = current->next;
        }
        return false;
    }
};

// Approach 2 - Optimized:
// Recursively check whether the current node's data matches key or recurse on next node.
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(n) due to recursion call stack in worst case

class SolutionRecursive {
public:
    bool search(Node* head, int key) {
        if (head == nullptr)
            return false;
        if (head->data == key)
            return true;
        return search(head->next, key);
    }
};
