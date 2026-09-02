#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Roman to Integer
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && mp[s[i]] < mp[s[i+1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }

    // Integer to Roman
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string ans = "";
        for (auto p : mp) {
            while (num >= p.first) {
                ans += p.second;
                num -= p.first;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("MCMXCIV") << endl;
    cout << sol.intToRoman(1994) << endl;
    return 0;
}
