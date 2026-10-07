#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calc(int n) {
        int rem = n % 4;
        if (rem == 0) return n;
        if (rem == 1) return 1;
        if (rem == 2) return n + 1;
        return 0; // if rem is 3
    }

public:
    int findXorLR(int l, int r) {
        int xr = calc(r);
        int xl = calc(l - 1);
        return xr ^ xl;
    }
};
