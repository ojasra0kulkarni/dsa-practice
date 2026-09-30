#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    void solve(int idx, int t, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans) {
        if (t == 0) {
            ans.push_back(curr);
            return;
        }
        if (t < 0 || idx == arr.size()) {
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i-1]) continue; // skip duplicates
            if (arr[i] > t) break; // optimization for sorted array

            curr.push_back(arr[i]);
            solve(i + 1, t - arr[i], arr, curr, ans);
            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, arr, curr, ans);
        return ans;
    }
};
