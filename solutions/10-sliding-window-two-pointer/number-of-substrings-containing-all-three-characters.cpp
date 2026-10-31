#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt[3] = {0};
        int ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - r);
                cnt[s[l] - 'a']--;
                l++;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};

int main() {
    Solution sol;
    cout<<sol.numberOfSubstrings("abcabc")<<endl;
    return 0;
}
