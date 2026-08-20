#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int>& w, int c, int d) {
        int cnt = 1;
        long long curr = 0;
        for(int x : w) {
            if(curr + x <= c) {
                curr += x;
            } else {
                cnt++;
                curr = x;
            }
        }
        return cnt <= d;
    }

public:
    int shipWithinDays(vector<int>& w, int d) {
        int sum = 0, mx = 0;
        for(int x : w) {
            sum += x;
            if(x > mx) mx = x;
        }

        int l = mx;
        int r = sum;
        int ans = sum;

        while(l <= r) {
            int mid = l + (r - l) / 2; // mid overflow
            if(check(w, mid, d)) { // can ship
                ans = mid;
                r = mid - 1;
            } else { // cannot ship
                l = mid + 1;
            }
        }
        return ans;
    }
};
