// Problem: Activity Selection 1587115620
// Link: https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <vector>
#include <algorithm>
using namespace std;

// Activity Selection
// Problem: Select the maximum number of non-overlapping activities given their start and finish times.

// Approach 1 - Brute Force:
// Generate all subsets of activities and pick the largest subset with no overlapping intervals.
// Time Complexity: O(2^n * n) due to subset generation and overlap checking
// Space Complexity: O(n) for recursion stack and subset storage

class Solution {
public:
    int maxActivities(int start[], int finish[], int n) {
        vector<pair<int,int>> activities;
        for(int i = 0; i < n; i++) 
            activities.push_back({start[i], finish[i]});
        
        int maxCount = 0;

        function<void(int,int,int)> backtrack = [&](int index, int lastFinish, int count) {
            if(index == n) {
                maxCount = max(maxCount, count);
                return;
            }
            // Skip current activity
            backtrack(index + 1, lastFinish, count);
            // Take current activity if no overlap
            if(activities[index].first > lastFinish) 
                backtrack(index + 1, activities[index].second, count + 1);
        };

        backtrack(0, -1, 0);
        return maxCount;
    }
};

// Approach 2 - Optimized:
// Sort activities by finish time. Iteratively select the next activity that starts after last selected activity finishes.
// This greedy approach ensures maximum activities.
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n) for sorting storage

class Solution {
public:
    int maxActivities(int start[], int finish[], int n) {
        vector<pair<int,int>> activities;
        for(int i = 0; i < n; i++) 
            activities.push_back({start[i], finish[i]});
        
        // Sort by finish time
        sort(activities.begin(), activities.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        
        int count = 1;  // Always pick the first activity after sorting
        int lastFinish = activities[0].second;

        for(int i = 1; i < n; i++) {
            if(activities[i].first > lastFinish) {
                count++;
                lastFinish = activities[i].second;
            }
        }

        return count;
    }
};
