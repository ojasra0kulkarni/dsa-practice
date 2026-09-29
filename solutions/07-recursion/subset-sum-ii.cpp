#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
private:
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        ans.push_back(curr);

        for(int i=idx; i<nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue; // skip duplicates
            curr.push_back(nums[i]);
            solve(i+1, curr, ans, nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        // cout<<ans.size()<<endl;
        return ans;
    }
};
