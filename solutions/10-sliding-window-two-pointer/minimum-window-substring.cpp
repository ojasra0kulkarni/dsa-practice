#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        if(m==0) return "";
        if(n==0) return "";
        if(n<m) return "";

        int arr_t[128]={0}; // target char frequencies
        for(char c:t){
            arr_t[c]++;
        }

        int arr_s[128]={0}; // window char frequencies
        int l=0, r=0;
        int matched=0; 
        int minLen=INT_MAX;
        int stIdx=-1;

        while(r<n){
            char c=s[r];
            arr_s[c]++;

            if(arr_t[c]>0 && arr_s[c]<=arr_t[c]){ // count required char
                matched++;
            }

            while(matched==m){ // window is valid
                if(r-l+1 < minLen){
                    minLen=r-l+1;
                    stIdx=l;
                }

                char lc=s[l];
                arr_s[lc]--;
                
                if(arr_t[lc]>0 && arr_s[lc]<arr_t[lc]){ 
                    matched--; 
                }
                l++;
            }
            r++;
        }

        if(stIdx==-1) return "";
        return s.substr(stIdx,minLen);
    }
};

// edge case: empty input handled above
