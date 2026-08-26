#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxRowIdx(vector<vector<int>>& mat, int c, int n) {
        int mx = -1;
        int idx = -1;
        for(int r=0;r<n;r++){
            if(mat[r][c]>mx){
                mx = mat[r][c];
                idx = r;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lo = 0, hi = m - 1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int r = findMaxRowIdx(mat, mid, n);

            int lft = (mid > 0) ? mat[r][mid-1] : -1;
            int rgt = (mid < m-1) ? mat[r][mid+1] : -1;

            if(mat[r][mid]>lft && mat[r][mid]>rgt){
                return {r, mid};
            } else if(mat[r][mid]<lft){
                hi = mid - 1;
            } else { // mat[r][mid] < rgt
                lo = mid + 1;
            }
        }
        return {-1, -1}; // Should not be reached
    }
};
