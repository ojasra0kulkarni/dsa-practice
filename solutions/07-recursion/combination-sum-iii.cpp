#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;

    void solve(int k, int n, int idx, int sum, int cnt) {
        if (sum == n && cnt == k) {
            res.push_back(temp);
            return;
        }
        if (sum > n || cnt >= k) {
            return;
        }

        for (int i=idx; i<=9; i++) {
            if (sum + i > n) { // current sum + next number already too big
                break;
            }
            if (9 - i + 1 < k - cnt) { // not enough elements left to pick
                break;
            }
            temp.push_back(i);
            solve(k, n, i + 1, sum + i, cnt + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 1, 0, 0);
        return res;
    }
};
