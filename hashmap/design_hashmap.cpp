// Problem: Design Hashmap
// Link: https://leetcode.com/problems/design-hashmap/description/

#include <vector>
#include <list>
using namespace std;

// Design HashMap
// Problem: Implement a hashmap with put, get, and remove without built-in hash tables

// Approach 1 - Brute Force:
// Use a simple vector with direct addressing, storing values at indices representing keys.
// Initialize all slots with -1 to denote empty.
// Time Complexity: O(1) for put/get/remove
// Space Complexity: O(10^6) due to fixed-size vector covering all possible keys.

class MyHashMap {
    vector<int> data;
public:
    MyHashMap() : data(1000001, -1) {}

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

// Approach 2 - Optimized:
// Use separate chaining with an array of buckets (vectors of list of pairs) to handle collisions.
// Hash function: key modulo bucket size.
// Each bucket stores key-value pairs; iterate bucket to find/update/remove keys.
// Time Complexity: Average O(1), Worst O(n) if many collisions
// Space Complexity: O(n) proportional to number of stored elements

class MyHashMap {
    static const int SIZE = 1000;
    vector<list<pair<int,int>>> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : buckets(SIZE) {}

    void put(int key, int value) {
        int i = hash(key);
        for (auto& kv : buckets[i]) {
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        buckets[i].emplace_back(key, value);
    }

    int get(int key) {
        int i = hash(key);
        for (auto& kv : buckets[i]) {
            if (kv.first == key) return kv.second;
        }
        return -1;
    }

    void remove(int key) {
        int i = hash(key);
        for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it) {
            if (it->first == key) {
                buckets[i].erase(it);
                return;
            }
        }
    }
};
