#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarrayWithSumK(vector<int> a, int k) {
        unordered_map<long long, int> mp; 
        long long sum = 0;
        int mx = 0;
        mp[0] = -1; // sum 0 found at index -1

        for(int i=0;i<a.size();i++){
            sum += a[i];
            if(mp.count(sum - k)){
                mx = max(mx, i - mp[sum - k]);
            }
            if(!mp.count(sum)){ // store first occurrence
                mp[sum] = i;
            }
        }
        return mx;
    }
};

// TODO: try the O(1) space version
