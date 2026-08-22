#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    bool possible(vector<int>& arr, int h, int k) {
        ll cnt = 0;
        for (int p : arr) {
            cnt += (p + k - 1) / k;
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n = arr.size();
        int lo = 1;
        int hi = 0;
        for (int p : arr) {
            if (p > hi) hi = p;
        }
        int ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (possible(arr, h, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
