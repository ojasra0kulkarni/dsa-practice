#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0,r=0;
        int cnt=0;
        int mx=0;

        for(r=0;r<n;r++){
            if(arr[r]==0) cnt++;
            while(cnt>k){
                if(arr[l]==0) cnt--;
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
    }
};
