#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        int n = v.size();
        if(n==0) return {};

        sort(v.begin(), v.end()); // sort by start times

        vector<vector<int>> ans;
        vector<int> curr = v[0];

        for(int i=1;i<n;i++) {
            if(v[i][0] <= curr[1]) {
                curr[1] = max(curr[1], v[i][1]);
            } else {
                ans.push_back(curr);
                curr = v[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = s.merge(a);
    for(auto &x : res) {
        cout << "[" << x[0] << "," << x[1] << "] ";
    }
    cout << endl;
    return 0;
}
