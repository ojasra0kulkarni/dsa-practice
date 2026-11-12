#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        if (n == 0) return 0;
        
        vector<int> cnt(n, 1);
        
        // left to right pass
        for (int i = 1; i < n; i++) {
            if (v[i] > v[i-1]) {
                cnt[i] = cnt[i-1] + 1;
            }
        }
        
        // right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] > v[i+1]) {
                cnt[i] = max(cnt[i], cnt[i+1] + 1);
            }
        }
        
        int sum = 0;
        for (int x : cnt) {
            sum += x;
        }
        
        return sum;
    }
};
