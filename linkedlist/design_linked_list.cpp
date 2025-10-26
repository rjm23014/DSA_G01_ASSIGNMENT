// Problem: Design Linked List
// Link: https://leetcode.com/problems/design-linked-list/description/

#include <iostream>
// No extra headers needed for pointer manipulation
using namespace std;

// Design Linked List
// Problem: Implement a singly linked list with get, addAtHead, addAtTail, addAtIndex, and deleteAtIndex operations.

// Approach 1 - Brute Force:
// Use a singly linked list without a dummy head; each operation traverses from head.
// Time Complexity: get/addAtIndex/deleteAtIndex: O(n), addAtHead: O(1), addAtTail: O(n)
// Space Complexity: O(n) for node storage

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val): val(val), next(nullptr) {}
    };
    Node* head;
public:
    MyLinkedList() : head(nullptr) {}

    int get(int index) {
        Node* curr = head;
        while (curr && index > 0) {
            curr = curr->next;
            index--;
        }
        return curr ? curr->val : -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; curr && i < index - 1; ++i) {
            curr = curr->next;
        }
        if (!curr) return; // index > length, do nothing
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || !head) return;
        if (index == 0) {
            Node* delNode = head;
            head = head->next;
            delete delNode;
            return;
        }
        Node* curr = head;
        for (int i = 0; curr && i < index - 1; ++i) {
            curr = curr->next;
        }
        if (!curr || !curr->next) return; // index invalid
        Node* delNode = curr->next;
        curr->next = delNode->next;
        delete delNode;
    }
};

// Approach 2 - Optimized:
// Use a dummy head node to simplify edge cases, maintain a size variable for bounds checking.
// Time Complexity: get/addAtIndex/deleteAtIndex: O(n), addAtHead: O(1), addAtTail: O(n)
// Space Complexity: O(n) for node storage

class MyLinkedListOptimized {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val=0, Node* next=nullptr): val(val), next(next) {}
    };
    Node* dummy; // sentinel node before head
    int size;
public:
    MyLinkedListOptimized() {
        dummy = new Node();
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = dummy->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        Node* pred = dummy;
        for (int i = 0; i < index; ++i) {
            pred = pred->next;
        }
        Node* newNode = new Node(val, pred->next);
        pred->next = newNode;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* pred = dummy;
        for (int i = 0; i < index; ++i) {
            pred = pred->next;
        }
        Node* delNode = pred->next;
        pred->next = delNode->next;
        delete delNode;
        --size;
    }

    ~MyLinkedListOptimized() {
        Node* curr = dummy;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
