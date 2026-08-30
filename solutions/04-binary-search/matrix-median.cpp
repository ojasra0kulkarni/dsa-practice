#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>> &mat, int n, int m) {
        int lo = 1, hi = 1e9;
        int ans = -1;
        int temp = n * m;
        int req = temp / 2 + 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            temp = 0; // count elements <= mid
            for (int i = 0; i < n; i++) {
                temp += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if (temp >= req) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};
