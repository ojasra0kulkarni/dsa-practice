#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int idx, string &s, string curr, vector<string> &ans) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        char digit = s[idx];
        string letters = mp[digit - '0'];

        for (char c : letters) {
            solve(idx + 1, s, curr + c, ans);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        solve(0, digits, "", ans);
        // cout<<ans.size()<<endl;
        return ans;
    }
};
