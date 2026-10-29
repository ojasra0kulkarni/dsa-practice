#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0;
        int mxlen=0;
        int mxf=0; 
        vector<int> cnt(26,0);

        for(int r=0;r<n;r++){
            cnt[s[r]-'A']++;
            mxf=max(mxf,cnt[s[r]-'A']);

            if((r-l+1)-mxf>k){
                cnt[s[l]-'A']--;
                l++;
                // mxf not updated on l++, ok
            }
            mxlen=max(mxlen,r-l+1);
        }
        return mxlen;
    }
};

// note to self: revisit the binary search variant
