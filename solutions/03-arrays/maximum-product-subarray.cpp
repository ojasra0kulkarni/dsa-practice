#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;

        long long ans=arr[0];
        long long mx=arr[0]; // current max product ending here
        long long mn=arr[0]; // current min product ending here

        for(int i=1;i<n;i++){
            long long x=arr[i];
            if(x<0) swap(mx,mn); // negative flips max/min

            mx=max(x, mx*x);
            mn=min(x, mn*x);
            
            ans=max(ans,mx);
        }
        // cout<<ans<<endl;
        return (int)ans;
    }
};
