#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0) return "";
        
        int st = 0;
        int mx = 1;

        for(int i=0;i<n;i++){
            // odd length palindrome, center s[i]
            int l = i, r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > mx){
                    mx = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }

            // even length palindrome, center s[i] and s[i+1]
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1 > mx){
                    mx = r-l+1;
                    st = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(st, mx);
    }
};
