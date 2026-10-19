#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        if(n==0) return 0; // edge case
        int l=0,r=n-1;
        int ans=0;
        int ml=0; // max height from left encountered
        int mr=0; // max height from right encountered
        while(l<=r){
            if(h[l]<=h[r]){
                if(h[l]>=ml) ml=h[l];
                else ans+=ml-h[l];
                l++;
            }else{
                if(h[r]>=mr) mr=h[r];
                else ans+=mr-h[r];
                r--;
            }
        }
        return ans;
    }
};
