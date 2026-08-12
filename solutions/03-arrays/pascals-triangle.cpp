#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> curr(i+1); // current row has i+1 elements
            curr[0]=1;
            curr[i]=1;
            for(int j=1;j<i;j++){
                curr[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(curr);
        }
        
        return res;
    }
};
