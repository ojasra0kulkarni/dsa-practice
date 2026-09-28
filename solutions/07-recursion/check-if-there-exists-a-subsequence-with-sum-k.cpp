#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    bool solve(int idx, int sum, int k, vector<int>& arr) {
        if(sum==k)return true;
        if(idx==arr.size())return false;

        return solve(idx+1, sum+arr[idx], k, arr) || solve(idx+1, sum, k, arr);
    }

    bool isSubsequenceSum(vector<int>& arr, int k) {
        return solve(0,0,k,arr);
    }
};
