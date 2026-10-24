#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        for (char c : num) {
            while (s.length()>0 && k>0 && s.back()>c) {
                s.pop_back();
                k--;
            }
            s.pb(c);
        }

        while (k>0) {
            s.pop_back();
            k--;
        }

        int i = 0;
        while (i < s.length()-1 && s[i] == '0') { // keep at least one digit if it's '0'
            i++;
        }
        string ans = s.substr(i);

        if (ans.empty()) return "0";
        return ans;
    }
};

// TODO: try the O(1) space version
