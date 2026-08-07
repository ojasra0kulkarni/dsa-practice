#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        if (n == 0) return ans;

        int mx = arr[n-1]; // max from right
        ans.push_back(mx);

        for(int i=n-2;i>=0;i--){
            if(arr[i]>mx){
                ans.push_back(arr[i]);
                mx=arr[i];
            }
        }
        // cout<<ans<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
