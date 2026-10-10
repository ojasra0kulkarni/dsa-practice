#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int n, int d) {
        if (n == INT_MIN && d == -1) return INT_MAX; // handle overflow

        long long N = abs((long long)n);
        long long D = abs((long long)d);

        long long ans = 0;
        for (int k = 31; k >= 0; k--) { // iterate through bit positions
            if ((D << k) <= N) {
                N -= (D << k);
                ans |= (1LL << k);
            }
        }

        bool neg = (n < 0) ^ (d < 0);
        if (neg) {
            ans = -ans;
        }
        
        return (int)ans;
    }
};

int main() {
    cout << Solution().divide(INT_MIN, -1) << endl;
    return 0;
}
