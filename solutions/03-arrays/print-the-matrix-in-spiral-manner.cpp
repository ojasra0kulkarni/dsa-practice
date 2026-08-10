#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        if (n == 0) return ans;
        int m = mat[0].size();

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {
            // Traverse right
            for (int i = left; i <= right; i++) {
                ans.pb(mat[top][i]);
            }
            top++;
            if (top > bottom) break; 

            // Traverse down
            for (int i = top; i <= bottom; i++) {
                ans.pb(mat[i][right]);
            }
            right--;
            if (left > right) break; 

            // Traverse left
            for (int i = right; i >= left; i--) {
                ans.pb(mat[bottom][i]);
            }
            bottom--;
            if (top > bottom) break; 

            // Traverse up
            for (int i = bottom; i >= top; i--) {
                ans.pb(mat[i][left]);
            }
            left++;
            if (left > right) break; 
        }
        return ans;
    }
};
