#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        if(n == 0) return false;
        int m = mat[0].size();
        if(m == 0) return false;

        int r = 0;
        int c = m - 1; // start from top-right

        while(r < n && c >= 0) {
            if(mat[r][c] == x) return true;
            else if(mat[r][c] < x) r++;
            else c--; // current value too large, move left
        }
        return false;
    }
};
