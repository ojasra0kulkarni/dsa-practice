#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string& s, int k) { // helper for at most k distinct
        int n = s.size();
        if(k<0) return 0;
        long long cnt = 0;
        int l = 0;
        unordered_map<char, int> mp;
        for(int r=0; r<n; r++) {
            mp[s[r]]++;
            while(mp.size() > k) {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }

    long long countSubstrings(string s, int k) {
        return solve(s, k) - solve(s, k - 1);
    }
};
