#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int r, int n, vector<vector<string>>& ans, vector<string>& curr, vector<bool>& col, vector<bool>& d1, vector<bool>& d2) {
        if(r==n) {
            ans.push_back(curr);
            return;
        }

        for(int j=0;j<n;j++) {
            if(!col[j] && !d1[r-j+n-1] && !d2[r+j]) {
                curr[r][j]='Q';
                col[j]=true;
                d1[r-j+n-1]=true;
                d2[r+j]=true;

                solve(r+1, n, ans, curr, col, d1, d2);

                col[j]=false;
                d1[r-j+n-1]=false;
                d2[r+j]=false;
                curr[r][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> d1(2*n-1, false);
        vector<bool> d2(2*n-1, false);
        solve(0, n, ans, curr, col, d1, d2);
        return ans;
    }
};
