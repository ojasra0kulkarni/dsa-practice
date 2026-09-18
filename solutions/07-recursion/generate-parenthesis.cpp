#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int o, int c, int n, string s, vector<string>& res) {
        if (o == n && c == n) {
            res.push_back(s);
            return;
        }

        if (o < n) {
            solve(o + 1, c, n, s + '(', res);
        }

        if (c < o) { // close count must be less than open
            solve(o, c + 1, n, s + ')', res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(0, 0, n, "", res);
        return res;
    }
};
