#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        if (v.empty()) return 0;

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        int n = v.size();
        int cnt = 0;
        int en = v[0][1];
        
        for (int i = 1; i < n; i++) {
            if (v[i][0] < en) {
                cnt++;
            } else {
                en = v[i][1];
            }
        }
        return cnt;
    }
};
