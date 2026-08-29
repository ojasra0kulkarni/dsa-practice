#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; // check lengths first

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (char c : t) {
            cnt[c - 'a']--;
        }

        for (int x : cnt) {
            if (x != 0) return false;
        }

        return true;
    }
};
