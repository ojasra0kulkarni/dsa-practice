#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int idx, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans) {
        if (idx == arr.size()) { // base case all elements processed
            ans.push_back(curr);
            return;
        }

        // pick current element
        curr.push_back(arr[idx]);
        solve(idx + 1, arr, curr, ans);
        curr.pop_back(); // backtrack

        // do not pick current element
        solve(idx + 1, arr, curr, ans);

    }
public:
    vector<vector<int>> allSubsequences(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, arr, curr, ans);
        return ans;
    }
};

// note to self: revisit the hashmap variant
