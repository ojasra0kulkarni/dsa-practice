#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<int, int> mp;
        int sum = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum == 0) mx = max(mx, i + 1);
            else if (mp.count(sum)) mx = max(mx, i - mp[sum]);
            else mp[sum] = i;
        }
        return mx;
    }
};
