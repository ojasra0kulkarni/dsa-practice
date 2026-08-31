#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        if (n != t.length()) return false;

        char mp1[256] = {0}; // init to null char
        char mp2[256] = {0};

        for (int i = 0; i < n; i++) {
            char c1 = s[i];
            char c2 = t[i];

            if (mp1[c1] == 0 && mp2[c2] == 0) {
                mp1[c1] = c2;
                mp2[c2] = c1;
            } else if (mp1[c1] != c2 || mp2[c2] != c1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isIsomorphic("egg", "add") << endl;
    return 0;
}
