#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atoi(string s) {
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') i++; // skip leading whitespace
        
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        int res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            // check overflow against int_max int_min bounds
            if (sign == 1) {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return INT_MAX;
            } else { // sign is -1
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 8)) return INT_MIN;
            }
            res = res * 10 + digit;
            i++;
        }
        return res * sign;
    }
};
