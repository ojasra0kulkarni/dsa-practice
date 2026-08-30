#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string curr = strs[i];
            while (curr.find(res) != 0) {
                res = res.substr(0, res.length() - 1);
                if (res.empty()) return "";
            }
        }
        return res;
    }
};
