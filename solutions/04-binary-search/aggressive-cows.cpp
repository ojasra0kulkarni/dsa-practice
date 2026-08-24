#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool chk(int mid, vector<int> &st, int k) {
        int cnt = 1;
        int lst = st[0];
        for (int i = 1; i < st.size(); i++) {
            if (st[i] - lst >= mid) {
                cnt++;
                lst = st[i];
            }
        }
        return cnt >= k;
    }

    int aggressiveCows(vector<int> &st, int k) {
        sort(st.begin(), st.end());
        int n = st.size();
        int lo = 1;
        int hi = st[n-1] - st[0];
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // mid overflow
            if (chk(mid, st, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
