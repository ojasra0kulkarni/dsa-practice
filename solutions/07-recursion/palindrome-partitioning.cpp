#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPal(string& s, int st, int en) {
        while(st<=en) {
            if(s[st++]!=s[en--]) return false;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& curr, vector<vector<string>>& ans) {
        int n = s.size();
        if(idx==n) {
            ans.push_back(curr);
            return;
        }

        for(int i=idx;i<n;i++) {
            if(isPal(s, idx, i)) {
                curr.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, s, curr, ans);
        return ans;
    }
};
