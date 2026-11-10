#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int lo = 0;
        int hi = 0;

        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else { 
                lo--;
                hi++;
            }
            lo = max(lo, 0);
            if (hi < 0) {
                return false;
            }
        }
        return lo == 0;
    }
};
