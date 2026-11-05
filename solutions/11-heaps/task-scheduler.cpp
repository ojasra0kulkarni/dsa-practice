#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        vector<int> freq(26, 0);
        for(char x : t) {
            freq[x - 'A']++;
        }

        int mx = 0;
        for(int x : freq) {
            if(x > mx) mx = x;
        }

        int cnt = 0;
        for(int x : freq) {
            if(x == mx) cnt++;
        }

        long long ans = (long long)(mx - 1) * (n + 1) + cnt;
        return max((long long)t.size(), ans);
    }
};
