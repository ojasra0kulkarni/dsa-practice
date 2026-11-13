#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        if(n==0) return ans;

        sort(v.begin(),v.end()); // sort by start time

        ans.push_back(v[0]);

        for(int i=1;i<n;i++){
            vector<int> &last = ans.back();
            vector<int> &curr = v[i];

            if(curr[0]<=last[1]){ // overlap
                last[1]=max(last[1],curr[1]);
            } else {
                ans.push_back(curr);
            }
        }
        // cout<<ans.size()<<endl;
        return ans;
    }
};
