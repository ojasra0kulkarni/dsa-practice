#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<int> replaceElementsWithRank(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> b = arr;
        sort(b.begin(), b.end());

        map<int, int> mp;
        int rank = 1;
        for (int x : b) {
            if (mp.find(x) == mp.end()) {
                mp[x] = rank++;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.pb(mp[arr[i]]);
        }
        return ans;
    }
};
