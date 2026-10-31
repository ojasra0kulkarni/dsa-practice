#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int solve(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int cnt = 0;
        int ans = 0;
        while (r < n) {
            mp[arr[r]]++;
            if (mp[arr[r]] == 1) {
                cnt++;
            }

            while (cnt > k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) {
                    cnt--;
                }
                l++;
            }
            ans += (r - l + 1); // add all subarrays ending at r
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
