#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp; // char to its last seen index
        int l=0;
        int ans=0;
        int n=s.size();

        for(int r=0;r<n;r++){
            if(mp.count(s[r])&&mp[s[r]]>=l){ // check if in current window
                l=mp[s[r]]+1;
            }
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
// ^ submitted, accepted
