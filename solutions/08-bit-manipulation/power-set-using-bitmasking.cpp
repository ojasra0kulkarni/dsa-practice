#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){ 
            vector<int> curr;
            for(int j=0;j<n;j++){
                if((i>>j)&1){ // check if jth bit is set
                    curr.push_back(arr[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
