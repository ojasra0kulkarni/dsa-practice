#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(vector<int>& arr, int k) {
        int n = arr.size();
        long long ans = 0;
        int l = 0, cnt = 0;
        for (int r = 0; r < n; r++) {
            if (arr[r] & 1) {
                cnt++;
            }
            while (cnt > k) {
                if (arr[l] & 1) {
                    cnt--;
                }
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& arr, int k) {
        // exactly k = at most k - at most k-1
        return solve(arr, k) - solve(arr, k - 1);
    }
};
