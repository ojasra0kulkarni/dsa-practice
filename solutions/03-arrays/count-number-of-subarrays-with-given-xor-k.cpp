#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>&arr, int k) {
        int n = arr.size();
        int ans = 0;
        int curr = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            curr ^= arr[i];
            int x = curr ^ k;
            if(mp.count(x)){
                ans += mp[x];
            }
            mp[curr]++;
        }
        return ans;
    }
};
