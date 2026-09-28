#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rec(int i, int t, vector<int>& arr, vector<int>& curr, vector<vector<int>>& ans) {
        if(t==0) {
            ans.push_back(curr);
            return;
        }
        if(i==arr.size()) {
            return;
        }

        if(arr[i]<=t) { // optimization
            curr.push_back(arr[i]);
            rec(i, t-arr[i], arr, curr, ans); // can reuse current element
            curr.pop_back(); // remove element for next path
        }

        rec(i+1, t, arr, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        rec(0, t, arr, curr, ans);
        return ans;
    }
};
