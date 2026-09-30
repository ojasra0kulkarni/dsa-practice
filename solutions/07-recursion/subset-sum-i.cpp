#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void f(int i, int s, vector<int>& arr, int n, vector<int>& ans) {
        if (i == n) {
            ans.push_back(s);
            return;
        }

        f(i + 1, s + arr[i], arr, n, ans);
        f(i + 1, s, arr, n, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        f(0, 0, arr, n, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
