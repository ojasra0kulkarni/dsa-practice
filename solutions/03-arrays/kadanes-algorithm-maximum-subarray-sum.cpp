#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& arr, int n) {
        long long mx = arr[0];
        long long curr = arr[0];

        for (int i = 1; i < n; i++) {
            curr = max((long long)arr[i], curr + arr[i]);
            mx = max(mx, curr);
        }
        return mx;
    }
};
