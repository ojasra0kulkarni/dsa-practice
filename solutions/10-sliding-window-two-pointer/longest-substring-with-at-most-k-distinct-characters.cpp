#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if (k == 0) return 0;

        int l = 0, ans = 0;
        map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]); // remove char if count is zero
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
