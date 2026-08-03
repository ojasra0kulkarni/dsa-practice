#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mp; // val -> idx
        vector<int> ans;
        int n = arr.size();
        int temp;

        for(int i=0;i<n;i++) {
            temp = target - arr[i]; // temp use 1: complement to find
            if(mp.count(temp)) {
                ans.push_back(mp[temp]);
                ans.push_back(i);
                return ans;
            }
            temp = arr[i]; // temp use 2: current num to insert
            mp[temp] = i;
        }
        return ans;
    }
};
