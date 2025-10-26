// Problem: Permutations (String)
// Link: https://leetcode.com/problems/permutations/description/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Approach 1 - Backtracking (DFS):
// Build permutations one character at a time while marking used indices. To handle
// duplicate characters, sort first and skip identical choices when the previous
// duplicate has not been used. Collect each completed permutation in the result.
// Time Complexity: O(n * n!)
// Space Complexity: O(n) recursion + O(n!) result storage.

class Solution {
public:
	vector<string> permuteUnique(string s) {
		sort(s.begin(), s.end());
		vector<string> res;
		string current;
		vector<int> used(s.size(), 0);
		backtrack(s, used, current, res);
		return res;
	}

private:
	void backtrack(const string& s, vector<int>& used, string& current, vector<string>& res) {
		if (current.size() == s.size()) {
			res.push_back(current);
			return;
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (used[i]) continue;
			if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue; // avoid duplicates
			used[i] = 1;
			current.push_back(s[i]);
			backtrack(s, used, current, res);
			current.pop_back();
			used[i] = 0;
		}
	}
};

// Approach 2 - Next Permutation Iterator:
// Sort the string and iteratively apply next_permutation to generate the remaining
// permutations in lexicographic order. Handles duplicates naturally.
// Time Complexity: O(n * n!)
// Space Complexity: O(1) auxiliary (excluding output).

class NextPermutationGenerator {
public:
	vector<string> generate(string s) {
		sort(s.begin(), s.end());
		vector<string> res;
		do {
			res.push_back(s);
		} while (next_permutation(s.begin(), s.end()));
		return res;
	}
};
