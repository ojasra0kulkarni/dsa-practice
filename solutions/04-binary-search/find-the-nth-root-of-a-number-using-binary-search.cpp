#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // This helper checks if x^p <= m
    bool check(long double x, int p, int m) {
        long double res = 1.0L;
        for (int i = 0; i < p; i++) {
            res *= x;
            if (res > m) return false; // early exit if exceeds m
        }
        return res <= m;
    }

    long double NthRoot(int n, int m) {
        long double lo = 0.0L, hi = max(1.0L, (long double)m);
        
        for (int i = 0; i < 100; i++) {
            long double mid = lo + (hi - lo) / 2.0L;
            if (check(mid, n, m)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
