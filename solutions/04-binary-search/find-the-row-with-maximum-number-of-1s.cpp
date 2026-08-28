#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        if (n == 0) return -1;
        int m = arr[0].size();
        if (m == 0) return -1;

        int r = 0;
        int c = m - 1;
        int ans = -1;

        while (r < n && c >= 0) {
            if (arr[r][c] == 1) {
                ans = r;
                c--; // found 1, try left in same row
            }
            else {
                r++; // no 1 at this pos or left, move to next row
            }
        }
        return ans;
    }
};
