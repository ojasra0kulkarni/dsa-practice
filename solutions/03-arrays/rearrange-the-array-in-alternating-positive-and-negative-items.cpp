#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int> pos, neg;
        for (int x : arr) {
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        vector<int> ans(arr.size());
        int p = 0, n = 0;

        for (int k = 0; k < arr.size(); k++) {
            if (k % 2 == 0) ans[k] = pos[p++];
            else ans[k] = neg[n++];
        }
        return ans;
    }
};
