#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    void solve(int idx, int n, string &s, vector<string> &ans) {
        if (idx == n) {
            ans.pb(s);
            return;
        }

        s.pb('0');
        solve(idx + 1, n, s, ans);
        s.pop_back(); // backtrack

        s.pb('1');
        solve(idx + 1, n, s, ans);
        s.pop_back();
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        string s = "";
        solve(0, n, s, ans);
        return ans;
    }
};
