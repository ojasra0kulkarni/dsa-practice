#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=x;
        int ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2; // mid overflow
            if(mid*mid==x){
                return mid;
            }
            if(mid*mid<x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};
